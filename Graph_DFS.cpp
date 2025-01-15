#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// Struktur Graf
struct Graph {
    int Destinations; // Jumlah destinasi (vertices)
    unordered_map<string, vector<string>> Adj; // unordered_map untuk merepresentasikan daftar ketetanggaan
};

// Menambahkan edge ke dalam graf
void AddLine(Graph &Tour, string Start, string Finish) {
    Tour.Adj[Start].push_back(Finish); // Terdapat garis penghubung antara Start dan Finish
}

// Fungsi untuk melakukan pencarian secara mendalam (DFS) pada graf menggunakan stack
void DFS(const Graph &Tour, const string &Start) {
    // Membuat unordered_map untuk melacak node yang telah dikunjungi
    unordered_map<string, bool> Visited;

    // Inisialisasi semua node sebagai belum dikunjungi
    for (const auto &Pair : Tour.Adj) {
        Visited[Pair.first] = false;
    }

    // Buat stack untuk melacak node yang akan dikunjungi
    stack<string> ToVisit;
    // Masukkan node awal ke dalam stack
    ToVisit.push(Start);

    // Selama stack tidak kosong
    while (!ToVisit.empty()) {
        // Ambil node dari stack
        string Current = ToVisit.top();
        ToVisit.pop();

        // Jika node belum dikunjungi
        if (!Visited[Current]) {
            // Tandai node sebagai telah dikunjungi
            Visited[Current] = true;
            cout << Current << " ---> "; // Mengeluarkan node saat ini

            // Iterasi melalui semua tetangga dari node saat ini
            for (const string &Next : Tour.Adj.at(Current)) {
                // Jika tetangga belum dikunjungi, masukkan ke dalam stack
                if (!Visited[Next]) {
                    ToVisit.push(Next);
                }
            }
        }
    }
}

//Negeri
//UNESA 
//UNAIR
//ITS
//UPN V JATIM
//PENS
//PPNS

//Swasta
//UBAYA
//UWKS
//UWM
//UNTAG 
//HANG TUAH
//UC
//UINSA 
//UMS

//UBAYA,UINSA,UNESA, UC, UNAIR, ITS

int main() {
    Graph StudyTour;
    StudyTour.Destinations = 14;

    int Choice;
    system("cls");
    cout << "========= Surabaya Study Tour Planner =========\n";
    cout << "Pilih jenis kampus yang ingin dituju?\n\n";
    cout << "1. Perguruan Tinggi Negeri\n";
    cout << "2. Perguruan Tinggi Swasta\n";
    cout << "3. Bebas\n";
    cout << "> ";
    cin >> Choice;
    cin.ignore();

    string Destination;

    switch (Choice){
    case 1:{
        AddLine(StudyTour,"UNAIR", "ITS");
        AddLine(StudyTour,"UNAIR", "UNESA");
        AddLine(StudyTour,"ITS", "PENS");
        AddLine(StudyTour,"ITS", "PPNS");
        AddLine(StudyTour,"ITS", "UPN");
        AddLine(StudyTour,"UNESA", "UNAIR");
        AddLine(StudyTour,"UPN", "ITS");
        AddLine(StudyTour,"PENS", "ITS");
        AddLine(StudyTour,"PENS", "PPNS");
        AddLine(StudyTour,"PPNS", "ITS");
        AddLine(StudyTour,"PPNS", "PENS");
        
        cout << "Tujuan pertama yang ingin dituju?\n\n";
        cout << "1. Universitas Airlangga (UNAIR)\n";
        cout << "2. Institut Teknologi Sepuluh November (ITS)\n";
        cout << "3. Universitas Negeri Surabaya (UNESA)\n";
        cout << "4. Universitas Pembangunan Negeri Veteran Jawa Timur (UPN)\n";
        cout << "5. Politeknik Elekronika Negeri Surabaya (PENS)\n";
        cout << "6. Politeknik Perkapalan Negeri Surabaya (PPNS)\n\n";
        cout << "(Masukkan singkatan kampus yang ingin dituju, cth : UNESA)\n";
        cout << "> ";
        getline(cin,Destination);

        DFS(StudyTour,Destination);
        cout << "Finish";
    }
    break;

    case 2:{
        AddLine(StudyTour,"UBAYA", "UNTAG");
        AddLine(StudyTour,"UBAYA", "UINSA");
        AddLine(StudyTour,"UWKS", "UINSA");
        AddLine(StudyTour,"UWKS", "UC");
        AddLine(StudyTour,"UWM", "UHT");
        AddLine(StudyTour,"UWM", "UMS");
        AddLine(StudyTour,"UNTAG", "UHT");
        AddLine(StudyTour,"UNTAG", "UBAYA");
        AddLine(StudyTour,"UNTAG", "UINSA");
        AddLine(StudyTour,"UHT", "UWM");
        AddLine(StudyTour,"UHT", "UNTAG");
        AddLine(StudyTour,"UHT", "UMS");
        AddLine(StudyTour,"UC", "UWKS");
        AddLine(StudyTour,"UC", "UMS");
        AddLine(StudyTour,"UINSA", "UBAYA");
        AddLine(StudyTour,"UINSA", "UWKS");
        AddLine(StudyTour,"UINSA", "UNTAG");
        AddLine(StudyTour,"UMS", "UWM");
        AddLine(StudyTour,"UMS", "UHT");
        AddLine(StudyTour,"UMS", "UC");

        cout << "Tujuan pertama yang ingin dituju?\n\n";
        cout << "1. Universitas Surabaya (UBAYA)\n";
        cout << "2. Universitas Wijaya Kusuma Surabaya (UWKS)\n";
        cout << "3. Universitas Katolik Widya Mandala (UWM)\n";
        cout << "4. Universitas 17 Agustus 1945 (UNTAG)\n";
        cout << "5. Universitas Hang Tuah (UHT)\n";
        cout << "6. Universitas Ciputra (UC)\n";
        cout << "7. Universitas Islam Negeri Sunan Ampel (UINSA)\n";
        cout << "8. Universitas Muhammadiyah Surabaya (UMS)\n";
        cout << "(Masukkan singkatan kampus yang ingin dituju, cth : UBAYA)\n";
        cout << "> ";
        getline(cin,Destination);

        DFS(StudyTour,Destination);
        cout << "Finish";
    }
    break;
    
    case 3:{
        Destination = "UBAYA";
        AddLine(StudyTour,"UBAYA", "UINSA");
        AddLine(StudyTour,"UINSA", "UNESA");
        AddLine(StudyTour,"UNESA", "UC");
        AddLine(StudyTour,"UC", "UNAIR");
        AddLine(StudyTour,"UNAIR", "ITS");
        cout << "Berikut adalah tujuan yang kami rekomendasikan: \n";

        DFS(StudyTour,Destination);
        cout << "Finish";
    }
    default:
        cout << "Input tidak valid";
    break;
    }
    
    return 0;
}

/*

========= Surabaya Study Tour Planner =========
Pilih jenis kampus yang ingin dituju?

1. Perguruan Tinggi Negeri
2. Perguruan Tinggi Swasta
3. Bebas
> 1
Tujuan pertama yang ingin dituju?

1. Universitas Airlangga (UNAIR)
2. Institut Teknologi Sepuluh November (ITS)
3. Universitas Negeri Surabaya (UNESA)
4. Universitas Pembangunan Negeri Veteran Jawa Timur (UPN)
5. Politeknik Elekronika Negeri Surabaya (PENS)
6. Politeknik Perkapalan Negeri Surabaya (PPNS)

(Masukkan singkatan kampus yang ingin dituju, cth : UNESA)
> UNESA
UNESA ---> UNAIR ---> ITS ---> PENS ---> PPNS ---> UPN ---> Finish

========= Surabaya Study Tour Planner =========
Pilih jenis kampus yang ingin dituju?

1. Perguruan Tinggi Negeri
2. Perguruan Tinggi Swasta
3. Bebas
> 1
Tujuan pertama yang ingin dituju?

1. Universitas Airlangga (UNAIR)
2. Institut Teknologi Sepuluh November (ITS)
3. Universitas Negeri Surabaya (UNESA)
4. Universitas Pembangunan Negeri Veteran Jawa Timur (UPN)
5. Politeknik Elekronika Negeri Surabaya (PENS)
6. Politeknik Perkapalan Negeri Surabaya (PPNS)

(Masukkan singkatan kampus yang ingin dituju, cth : UNESA)
> UNAIR
UNAIR ---> UNESA ---> ITS ---> UPN ---> PPNS ---> PENS ---> Finish

========= Surabaya Study Tour Planner =========
Pilih jenis kampus yang ingin dituju?

1. Perguruan Tinggi Negeri
2. Perguruan Tinggi Swasta
3. Bebas
> 2
Tujuan pertama yang ingin dituju?

1. Universitas Surabaya (UBAYA)
2. Universitas Wijaya Kusuma Surabaya (UWKS)
3. Universitas Katolik Widya Mandala (UWM)
4. Universitas 17 Agustus 1945 (UNTAG)
5. Universitas Hang Tuah (UHT)
6. Universitas Ciputra (UC)
7. Universitas Islam Negeri Sunan Ampel (UINSA)
8. Universitas Muhammadiyah Surabaya (UMS)
(Masukkan singkatan kampus yang ingin dituju, cth : UBAYA)
> UWKS
UWKS ---> UINSA ---> UBAYA ---> UNTAG ---> UHT ---> UWM ---> UMS ---> UC ---> Finish

========= Surabaya Study Tour Planner =========
Pilih jenis kampus yang ingin dituju?

1. Perguruan Tinggi Negeri
2. Perguruan Tinggi Swasta
3. Bebas
> 2
Tujuan pertama yang ingin dituju?

1. Universitas Surabaya (UBAYA)
2. Universitas Wijaya Kusuma Surabaya (UWKS)
3. Universitas Katolik Widya Mandala (UWM)
4. Universitas 17 Agustus 1945 (UNTAG)
5. Universitas Hang Tuah (UHT)
6. Universitas Ciputra (UC)
7. Universitas Islam Negeri Sunan Ampel (UINSA)
8. Universitas Muhammadiyah Surabaya (UMS)
(Masukkan singkatan kampus yang ingin dituju, cth : UBAYA)
> UNTAG
UNTAG ---> UINSA ---> UWKS ---> UC ---> UMS ---> UHT ---> UWM ---> UBAYA ---> Finish

========= Surabaya Study Tour Planner =========
Pilih jenis kampus yang ingin dituju?

1. Perguruan Tinggi Negeri
2. Perguruan Tinggi Swasta
3. Bebas
> 3
Berikut adalah tujuan yang kami rekomendasikan: 
UBAYA ---> UINSA ---> UNESA ---> UC ---> UNAIR ---> ITS ---> Finish*/