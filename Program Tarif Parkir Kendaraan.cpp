#include <iostream>
#include <string>
using namespace std;

struct Node {
    int JKendaraan, waktu, harga, biaya;
    string plat, tanggal;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}

    // Method untuk menambahkan data baru ke linked list
    void addData(int JKendaraan, const string& plat, const string& tanggal, int waktu, int harga, int biaya) {
        Node* newNode = new Node;
        newNode->JKendaraan = JKendaraan;
        newNode->plat = plat;
        newNode->tanggal = tanggal;
        newNode->waktu = waktu;
        newNode->harga = harga;
        newNode->biaya = biaya;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method untuk menampilkan seluruh data dalam linked list
    void displayData() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Jenis Kendaraan\t: ";
            if (temp->JKendaraan == 1)
                cout << "Mobil" << endl;
            else if (temp->JKendaraan == 2)
                cout << "Motor" << endl;
            cout << "Plat Nomor\t: " << temp->plat << endl;
            cout << "Tanggal\t\t: " << temp->tanggal << endl;
            cout << "Lama Parkir\t: " << temp->waktu << " jam" << endl;
            cout << "Biaya\t\t: " << temp->biaya << " IDR" << endl; // Output harga
            cout << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList dataKendaraan;

    // Menambahkan beberapa data kendaraan di awal
    dataKendaraan.addData(1, "B 4545 FMD", "2024-04-01", 2, 5000, 10000);
    dataKendaraan.addData(2, "B 2444 ZCM", "2024-04-01", 3, 2000, 6000);

    cout << "--- PROGRAM C++ TARIF PARKIR KENDARAAN ---" << endl;
    cout << "1. Tambahkan Kendaraan" << endl;
    cout << "2. Tampilkan Data Kendaraan" << endl;
    cout << "3. Keluar" << endl;
    cout << endl;
    cout << "Pilih opsi: ";

    int opsi;
    cin >> opsi;
    cin.ignore(); // Membersihkan newline dari buffer

    string plat, tanggal;
    int waktu, harga, biaya;

    while (opsi != 3) {
        switch (opsi) {
            case 1:
                cout << "\n--- Pilih Jenis Kendaraan Anda ---" << endl;
                cout << "1. Mobil" << endl;
                cout << "2. Motor" << endl;
                cout << endl;
                cout << "Masukan Jenis Kendaraan (1/2)\t: ";
                int JKendaraan;
                cin >> JKendaraan;
                cin.ignore(); // Membersihkan newline dari buffer

                switch (JKendaraan) {
                    case 1:
                        cout << "\nJenis Kendaraan\t\t: Mobil\n";
                        cout << "Masukkan Plat\t\t: ";
                        getline(cin, plat);
                        cout << "Masukkan Tanggal(TAHUN-BULAN-TANGGAL): ";
                        getline(cin, tanggal);
                        cout << "Lama Parkir (perjam)\t: ";
                        cin >> waktu;
                        harga = 5000;
                        biaya = waktu * harga;
                        cout << "Biaya\t\t\t: " << biaya << " IDR" << endl; // Output harga
                        dataKendaraan.addData(JKendaraan, plat, tanggal, waktu, harga, biaya);
                        break;
                    case 2:
                        cout << "\nJenis Kendaraan\t\t: Motor\n";
                        cout << "Masukkan Plat\t\t: ";
                        getline(cin, plat);
                        cout << "Masukkan Tanggal(TAHUN-BULAN-TANGGAL): ";
                        getline(cin, tanggal);
                        cout << "Lama Parkir (perjam)\t: ";
                        cin >> waktu;
                        harga = 2000;
                        biaya = waktu * harga;
                        cout << "Biaya\t\t\t: " << biaya << " IDR" << endl; // Output harga
                        dataKendaraan.addData(JKendaraan, plat, tanggal, waktu, harga, biaya);
                        break;
                    default:
                        cout << "Anda salah memasukkan angka";
                }
                break;
            case 2:
                cout << "\n--- Menampilkan Hasil ---\n";
                dataKendaraan.displayData();
                break;
            default:
                cout << "Opsi tidak valid.";
        }

        cout << "\n\n--- MENU ---" << endl;
        cout << "1. Tambahkan Kendaraan" << endl;
        cout << "2. Tampilkan Data Kendaraan" << endl;
        cout << "3. Keluar" << endl;
        cout << endl;
        cout << "Pilih opsi: ";
        cin >> opsi;
        cin.ignore(); // Membersihkan newline dari buffer
    }
    cout << "Program ini dibuat oleh Syafiq Afifful Azmi" << endl;
    cout << "NPM: 2310631170153" << endl;
    cout << "Program selesai." << endl;
    return 0;
}
