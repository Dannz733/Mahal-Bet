#include <iostream>
#include <string>
using namespace std;

const int MAX_NOVEL = 10;

struct Novel {
    string title;
    string author;
    int quantity;
};

void printMenu() {
    cout << "\nM E N U" << endl;
    cout << "1. Tambah Buku Novel" << endl;
    cout << "2. Tampilkan Data Buku Novel" << endl;
    cout << "3. Update Data Buku Novel" << endl;
    cout << "4. Hapus Data Buku Novel" << endl;
    cout << "5. Keluar" << endl;
}

void tambahNovel(Novel novelList[], int &numNovel) {
    if (numNovel < MAX_NOVEL) {
        cout << "Masukkan judul novel: ";
        cin.ignore();
        getline(cin, novelList[numNovel].title);
        cout << "Masukkan nama penulis: ";
        getline(cin, novelList[numNovel].author);
        cout << "Masukkan jumlah novel: ";
        cin >> novelList[numNovel].quantity;
        numNovel++;
        cout << "Novel berhasil ditambahkan!" << endl;
    } else {
        cout << "Maaf, sudah mencapai batas maksimal buku novel yang dapat ditambahkan." << endl;
    }
}

void tampilkanDataNovel(Novel novelList[], int numNovel) {
    if (numNovel == 0) {
        cout << "Tidak ada data buku novel yang tersedia." << endl;
    } else {
        cout << "Data Buku Novel:" << endl;
        for (int i = 0; i < numNovel; ++i) {
            cout << "Novel ke-" << i+1 << endl;
            cout << "Judul: " << novelList[i].title << endl;
            cout << "Penulis: " << novelList[i].author << endl;
            cout << "Jumlah: " << novelList[i].quantity << endl;
        }
    }
}

void updateDataNovel(Novel novelList[], int numNovel) {
    if (numNovel == 0) {
        cout << "Tidak ada data buku novel yang tersedia." << endl;
    } else {
        string title;
        cout << "Masukkan judul novel yang ingin diupdate: ";
        cin.ignore();
        getline(cin, title);
        bool found = false;
        for (int i = 0; i < numNovel; ++i) {
            if (novelList[i].title == title) {
                cout << "Masukkan jumlah baru: ";
                cin >> novelList[i].quantity;
                found = true;
                cout << "Data buku novel berhasil diupdate!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Buku novel dengan judul " << title << " tidak ditemukan." << endl;
        }
    }
}

void deleteDataNovel(Novel novelList[], int &numNovel) {
    if (numNovel == 0) {
        cout << "Tidak ada data buku novel yang tersedia." << endl;
    } else {
        string title;
        cout << "Masukkan judul novel yang ingin dihapus: ";
        cin.ignore();
        getline(cin, title);
        bool found = false;
        for (int i = 0; i < numNovel; ++i) {
            if (novelList[i].title == title) {
                for (int j = i; j < numNovel - 1; ++j) {
                    novelList[j] = novelList[j + 1];
                }
                numNovel--;
                found = true;
                cout << "Data buku novel berhasil dihapus!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Buku novel dengan judul " << title << " tidak ditemukan." << endl;
        }
    }
}

int main() {
    Novel novelList[MAX_NOVEL];
    int numNovel = 0;

    int counter_login = 0;
    while (true) {
        string nama, nim;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "fathir" && nim == "057") {
            cout << "Login berhasil!\n\n";
            break;
        } else {
            counter_login++;
            if (counter_login == 3) {
                cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
                return 0;
            } else {
                cout << "Login gagal. Silakan coba lagi.\n\n";
            }
        }
    }

    while (true) {
        printMenu();
        int Pilihan;
        cout << "Menu : ";
        cin >> Pilihan;

        switch (Pilihan) {
            case 1:
                tambahNovel(novelList, numNovel);
                break;
            case 2:
                tampilkanDataNovel(novelList, numNovel);
                break;
            case 3:
                updateDataNovel(novelList, numNovel);
                break;
            case 4:
                deleteDataNovel(novelList, numNovel);
                break;
            case 5:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    }

    return 0;
}
