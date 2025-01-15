#include <iostream>
#include <string>
using namespace std;

struct destinasi {
    string tempat;
    destinasi* next;
};

struct graph {
    int banyak_tempat;
    string tempat[10];
    destinasi* adj[10];
};

void tambahGaris(graph &tur, string mulai, string selesai) {
    int indeksMulai = -1, indeksSelesai = -1;
    for (int i = 0; i < tur.banyak_tempat; i++) {
        if (tur.tempat[i] == mulai) indeksMulai = i;
        if (tur.tempat[i] == selesai) indeksSelesai = i;
    }

    if (indeksMulai != -1 && indeksSelesai != -1) {
        destinasi* baru = new destinasi{selesai, tur.adj[indeksMulai]};
        tur.adj[indeksMulai] = baru;
    }
}

void BFS(graph &tur, string mulai) {
    bool dikunjungi[10] = {false};
    string antrianTur[10];
    int depan = 0, belakang = 0;

    int indeksMulai = -1;
    for (int i = 0; i < tur.banyak_tempat; i++) {
        if (tur.tempat[i] == mulai) {
            indeksMulai = i;
            break;
        }
    }

    if (indeksMulai == -1) return;

    dikunjungi[indeksMulai] = true;
    antrianTur[belakang++] = mulai;

    while (depan < belakang) {
        string mulaiTur = antrianTur[depan++];
        cout << mulaiTur << " ---> ";

        int indeksSaatIni = -1;
        for (int i = 0; i < tur.banyak_tempat; i++) {
            if (tur.tempat[i] == mulaiTur) {
                indeksSaatIni = i;
                break;
            }
        }

        destinasi* daftarAdj = tur.adj[indeksSaatIni];
        while (daftarAdj != nullptr) {
            int adjIndeks = -1;
            for (int i = 0; i < tur.banyak_tempat; i++) {
                if (tur.tempat[i] == daftarAdj->tempat) {
                    adjIndeks = i;
                    break;
                }
            }

            if (!dikunjungi[adjIndeks]) {
                dikunjungi[adjIndeks] = true;
                antrianTur[belakang++] = daftarAdj->tempat;
            }
            daftarAdj = daftarAdj->next;
        }
    }
    cout << "Finish\n";
}

int main() {
    graph SurabayaTourism;
    SurabayaTourism.banyak_tempat = 10;
    string tempat[10] = {
        "Arab Village", "Bulak Village", "Sanggar Agung Temple", 
        "4 Face Buddha Statue", "Museum House of Sampoerna", 
        "Food Junction Grand Pakuwon", "Heroes Monument", 
        "Heroes Museum", "The Statue of Suro and Boyo", "Surabaya Zoo"
    };
    
    for (int i = 0; i < 10; i++) {
        SurabayaTourism.tempat[i] = tempat[i];
        SurabayaTourism.adj[i] = nullptr;
    }

    tambahGaris(SurabayaTourism, "Arab Village", "Museum House of Sampoerna");
    tambahGaris(SurabayaTourism, "Arab Village", "Bulak Village");
    tambahGaris(SurabayaTourism, "Bulak Village", "4 Face Buddha Statue");
    tambahGaris(SurabayaTourism, "Bulak Village", "Sanggar Agung Temple");
    tambahGaris(SurabayaTourism, "Bulak Village", "Arab Village");
    tambahGaris(SurabayaTourism, "Sanggar Agung Temple", "4 Face Buddha Statue");
    tambahGaris(SurabayaTourism, "Sanggar Agung Temple", "Bulak Village");
    tambahGaris(SurabayaTourism, "4 Face Buddha Statue", "Sanggar Agung Temple");
    tambahGaris(SurabayaTourism, "4 Face Buddha Statue", "Bulak Village");
    tambahGaris(SurabayaTourism, "Museum House of Sampoerna", "Arab Village");
    tambahGaris(SurabayaTourism, "Museum House of Sampoerna", "Heroes Monument");
    tambahGaris(SurabayaTourism, "Museum House of Sampoerna", "Heroes Museum");
    tambahGaris(SurabayaTourism, "Museum House of Sampoerna", "Food Junction Grand Pakuwon");
    tambahGaris(SurabayaTourism, "Food Junction Grand Pakuwon", "Museum House of Sampoerna");
    tambahGaris(SurabayaTourism, "Food Junction Grand Pakuwon", "Heroes Monument");
    tambahGaris(SurabayaTourism, "Heroes Monument", "Heroes Museum");
    tambahGaris(SurabayaTourism, "Heroes Monument", "Museum House of Sampoerna");
    tambahGaris(SurabayaTourism, "Heroes Monument", "Food Junction Grand Pakuwon");
    tambahGaris(SurabayaTourism, "Heroes Monument", "The Statue of Suro and Boyo");
    tambahGaris(SurabayaTourism, "Heroes Museum", "Heroes Monument");
    tambahGaris(SurabayaTourism, "Heroes Museum", "The Statue of Suro and Boyo");
    tambahGaris(SurabayaTourism, "Heroes Museum", "Museum House of Sampoerna");
    tambahGaris(SurabayaTourism, "The Statue of Suro and Boyo", "Surabaya Zoo");
    tambahGaris(SurabayaTourism, "The Statue of Suro and Boyo", "Heroes Monument");
    tambahGaris(SurabayaTourism, "The Statue of Suro and Boyo", "Heroes Museum");
    tambahGaris(SurabayaTourism, "Surabaya Zoo", "The Statue of Suro and Boyo");

    string Destinasi;
    cout << "========= Surabaya Destination Planner =========\n";
    cout << "Where is your destination?\n\n";
    cout << "1. Arab Village (Kampung Arab), North Surabaya\n";
    cout << "2. Bulak Village (Kampung Bulak), North Surabaya\n";
    cout << "3. Sanggar Agung Temple (Klenteng Sanggar Agung), North Surabaya\n";
    cout << "4. 4 Face Buddha Statue (Patung Buddha 4 Rupa), North Surabaya\n";
    cout << "5. Museum House of Sampoerna, North Surabaya\n";
    cout << "6. Food Junction Grand Pakuwon, West Surabaya\n";
    cout << "7. Heroes Monument (Tugu Pahlawan), Central Surabaya\n";
    cout << "8. Heroes Museum (Museum Pahlawan), Central Surabaya\n";
    cout << "9. The Statue of Suro and Boyo (Patung Suro dan Boyo), South Surabaya\n";
    cout << "10. Surabaya Zoo (Kebun Binatang Surabaya), South Surabaya\n\n";
    cout << "> ";

    getline(cin, Destinasi);

    cout << "\nYour destination is " << Destinasi << endl;
    cout << "Stay safe and happy travel, maybe we can suggest tourist destinations that are close to your destination: \n\n";
    BFS(SurabayaTourism, Destinasi);

    return 0;
}
