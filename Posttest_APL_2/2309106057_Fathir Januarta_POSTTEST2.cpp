#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data peminjam
struct Peminjam {
    string nama;
    string nim;
};

// Struktur untuk menyimpan data buku novel
struct BukuNovel {
    string judul;
    string pengarang;
    int stok;
};

// Fungsi untuk menampilkan menu peminjaman buku
void tampilkanMenuBuku() {
    cout << "\n=== M E N U ===" << endl;
    cout << "1. Pinjam Buku" << endl;
    cout << "2. Lihat Daftar Buku" << endl;
    cout << "3. Update Judul dan Stok Buku" << endl;
    cout << "4. Kembalikan Buku" << endl;
    cout << "5. Keluar" << endl;
}

// Fungsi untuk melakukan login
bool loginPeminjam() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    return (nama == "Fathir" && nim == "057");
}

// Fungsi untuk menambahkan buku baru
void pinjamBuku(BukuNovel daftarBuku[], int& jumlahBuku, const int MAX_BUKU) {
    if (jumlahBuku < MAX_BUKU) {
        cout << "Masukkan judul buku: ";
        cin.ignore();
        getline(cin, daftarBuku[jumlahBuku].judul);
        cout << "Masukkan pengarang buku: ";
        getline(cin, daftarBuku[jumlahBuku].pengarang);
        cout << "Masukkan stok buku: ";
        cin >> daftarBuku[jumlahBuku].stok;
        jumlahBuku++; // Tambah jumlah buku dalam daftar
    } else {
        cout << "Daftar buku penuh!" << endl;
    }
}

// Fungsi untuk menampilkan daftar buku
void lihatDaftarBuku(const BukuNovel daftarBuku[], const int jumlahBuku) {
    if (jumlahBuku > 0) {
        cout << "=== DAFTAR BUKU ===" << endl;
        cout << "ID\tJudul\tPengarang\tStok" << endl;
        for (int i = 0; i < jumlahBuku; i++) {
            cout << i + 1 << "\t";
            cout << daftarBuku[i].judul << "\t";
            cout << daftarBuku[i].pengarang << "\t";
            cout << daftarBuku[i].stok << endl;
        }
    } else {
        cout << "Daftar buku kosong!" << endl;
    }
}

// Fungsi untuk mengupdate judul dan stok buku
void updateJudulDanStokBuku(BukuNovel daftarBuku[], const int jumlahBuku) {
    if (jumlahBuku > 0) {
        int indeks;
        cout << "Masukkan nomor buku yang ingin diupdate: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahBuku) {
            cout << "Masukkan judul baru: ";
            cin.ignore();
            getline(cin, daftarBuku[indeks - 1].judul);
            cout << "Masukkan stok baru: ";
            cin >> daftarBuku[indeks - 1].stok;
            cout << "Informasi buku berhasil diperbarui." << endl;
        } else {
            cout << "Nomor buku tidak valid!" << endl;
        }
    } else {
        cout << "Daftar buku kosong!" << endl;
    }
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku(BukuNovel daftarBuku[], int& jumlahBuku) {
    if (jumlahBuku > 0) {
        int indeks;
        cout << "Masukkan nomor buku yang ingin dikembalikan: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahBuku) {
            daftarBuku[indeks - 1].stok++;
            cout << "Buku berhasil dikembalikan." << endl;
        } else {
            cout << "Nomor buku tidak valid!" << endl;
        }
    } else {
        cout << "Daftar buku kosong!" << endl;
    }
}

int main() {
    const int MAX_BUKU = 100;
    BukuNovel daftarBuku[MAX_BUKU];
    int jumlahBuku = 0;

    while (true) {
        if (loginPeminjam()) {
            while (true) {
                tampilkanMenuBuku();
                int pilihan;
                cout << "Pilihan: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        pinjamBuku(daftarBuku, jumlahBuku, MAX_BUKU);
                        break;
                    case 2:
                        lihatDaftarBuku(daftarBuku, jumlahBuku);
                        break;
                    case 3:
                        lihatDaftarBuku(daftarBuku, jumlahBuku);
                        updateJudulDanStokBuku(daftarBuku, jumlahBuku);
                        break;
                    case 4:
                        kembalikanBuku(daftarBuku, jumlahBuku);
                        break;
                    case 5:
                        cout << "Keluar dari program, Terima kasih telah menggunakan program kami." << endl;
                        return 0;
                    default:
                        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                        break;
                }
            }
        } else {
            cout << "Login gagal. Nama atau NIM salah." << endl;
            return 0;
        }
    }

    return 0;
}
