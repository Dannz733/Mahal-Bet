#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Algoritma sorting

// Bubble Sort untuk sorting huruf secara ascending
void bubbleSortAscending(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort untuk sorting angka secara descending
void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

// Quick Sort untuk sorting secara ascending
void quickSortAscending(string arr[], int low, int high);

// Partition untuk Quick Sort
int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Implementasi Quick Sort untuk sorting secara ascending
void quickSortAscending(string arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSortAscending(arr, low, pivot - 1);
        quickSortAscending(arr, pivot + 1, high);
    }
}

// Algoritma searching

// Binary Search untuk mencari data pada kumpulan data yang terurut secara ascending
int binarySearchAscending(const string arr[], int n, string x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Linear Search untuk mencari data pada kumpulan data yang terurut secara descending
int linearSearchDescending(const string arr[], int n, string x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Struct untuk menyimpan informasi buku non-fiksi
struct BukuNonFiksi {
    string judul;
    string pengarang;
    int stok;
};

// Struct untuk menyimpan informasi buku
struct Buku {
    BukuNonFiksi nonFiksi;
};

// Menampilkan menu buku
void tampilkanMenuBuku() {
    cout << "\n=== M E N U ===" << endl;
    cout << "1. Pinjam Buku" << endl;
    cout << "2. Lihat Daftar Buku" << endl;
    cout << "3. Update Judul dan Stok Buku" << endl;
    cout << "4. Kembalikan Buku" << endl;
    cout << "5. Keluar" << endl;
}

// Fungsi untuk meminta login peminjam
bool loginPeminjam() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    return (nama == "Fathir" && nim == "057");
}

// Fungsi untuk pinjam buku
void pinjamBuku(Buku *buku, int& jumlahBuku, const int MAX_BUKU) {
    if (jumlahBuku < MAX_BUKU) {
        cout << "Masukkan judul buku: ";
        cin.ignore();
        getline(cin, buku[jumlahBuku].nonFiksi.judul);
        cout << "Masukkan pengarang buku: ";
        getline(cin, buku[jumlahBuku].nonFiksi.pengarang);
        cout << "Masukkan stok buku: ";
        cin >> buku[jumlahBuku].nonFiksi.stok;
        jumlahBuku++; 
    } else {
        cout << "Daftar buku penuh!" << endl;
    }
}

// Fungsi untuk melihat daftar buku
void lihatDaftarBuku(const Buku *buku, const int jumlahBuku) {
    if (jumlahBuku > 0) {
        cout << "=== DAFTAR BUKU ===" << endl;
        cout << "ID\tJudul\tPengarang\tStok" << endl;
        for (int i = 0; i < jumlahBuku; i++) {
            cout << i + 1 << "\t";
            cout << buku[i].nonFiksi.judul << "\t";
            cout << buku[i].nonFiksi.pengarang << "\t";
            cout << buku[i].nonFiksi.stok << endl;
        }
    } else {
        cout << "Daftar buku kosong!" << endl;
    }
}

// Fungsi untuk mengupdate judul dan stok buku
void updateJudulDanStokBuku(Buku *buku, const int jumlahBuku) {
    if (jumlahBuku > 0) {
        int indeks;
        cout << "Masukkan nomor buku yang ingin diupdate: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahBuku) {
            cout << "Masukkan judul baru: ";
            cin.ignore();
            getline(cin, buku[indeks - 1].nonFiksi.judul);
            cout << "Masukkan stok baru: ";
            cin >> buku[indeks - 1].nonFiksi.stok;
            cout << "Informasi buku berhasil diperbarui." << endl;
        } else {
            cout << "Nomor buku tidak valid!" << endl;
        }
    } else {
        cout << "Daftar buku kosong!" << endl;
    }
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku(Buku *buku, int& jumlahBuku) {
    if (jumlahBuku > 0) {
        int indeks;
        cout << "Masukkan nomor buku yang ingin dikembalikan: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahBuku) {
            for (int i = indeks - 1; i < jumlahBuku - 1; ++i) {
                buku[i] = buku[i + 1];
            }
            jumlahBuku--; 
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
    Buku *daftarBuku = new Buku[MAX_BUKU];
    int jumlahBuku = 0;

    string huruf[] = {"d", "b", "c", "a", "e"};
    int angka[] = {5, 2, 4, 1, 3};
    
    string daftarKata[] = {"apple", "banana", "grape", "orange", "pear"};
    string cari = "grape";

    // Sorting huruf menggunakan Bubble Sort
    bubbleSortAscending(huruf, 5);
    cout << "Huruf setelah diurutkan secara ascending: ";
    for (int i = 0; i < 5; ++i) {
        cout << huruf[i] << " ";
    }
    cout << endl;

    // Sorting angka menggunakan Selection Sort
    selectionSortDescending(angka, 5);
    cout << "Angka setelah diurutkan secara descending: ";
    for (int i = 0; i < 5; ++i) {
        cout << angka[i] << " ";
    }
    cout << endl;

    // Searching kata menggunakan Binary Search
    int hasilBinarySearch = binarySearchAscending(daftarKata, 5, cari);
    if (hasilBinarySearch != -1) {
        cout << "Kata \"" << cari << "\" ditemukan pada indeks " << hasilBinarySearch << " setelah diurutkan secara ascending." << endl;
    } else {
        cout << "Kata \"" << cari << "\" tidak ditemukan." << endl;
    }

    // Searching kata menggunakan Linear Search
    int hasilLinearSearch = linearSearchDescending(daftarKata, 5, cari);
    if (hasilLinearSearch != -1) {
        cout << "Kata \"" << cari << "\" ditemukan pada indeks " << hasilLinearSearch << " setelah diurutkan secara descending." << endl;
    } else {
        cout << "Kata \"" << cari << "\" tidak ditemukan." << endl;
    }

    bool logged_in = loginPeminjam();

    if (!logged_in) {
        cout << "Login gagal. Keluar dari program." << endl;
        return 1;
    }

    tampilkanMenuBuku();

    int pilihan;
    while (true) {
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pinjamBuku(daftarBuku, jumlahBuku, MAX_BUKU);
                break;
            case 2:
                lihatDaftarBuku(daftarBuku, jumlahBuku);
                break;
            case 3:
                updateJudulDanStokBuku(daftarBuku, jumlahBuku);
                break;
            case 4:
                kembalikanBuku(daftarBuku, jumlahBuku);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                delete[] daftarBuku;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
