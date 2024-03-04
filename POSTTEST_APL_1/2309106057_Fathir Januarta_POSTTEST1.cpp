#include <iostream>
#include <string>

using namespace std;

// Function to convert Kilometer per hour to other units
void km_per_hour_to_other(double km_per_hour) {
    cout << km_per_hour << " Kilometer per jam = " << km_per_hour * 27.7778 << " Centimeter per detik\n";
    cout << km_per_hour << " Kilometer per jam = " << km_per_hour * 0.277778 << " Meter per detik\n";
    cout << km_per_hour << " Kilometer per jam = " << km_per_hour / 1.60934 << " Mil per jam\n";
}

// Function to convert Centimeter per second to other units
void cm_per_second_to_other(double cm_per_second) {
    cout << cm_per_second << " Centimeter per detik = " << cm_per_second * 0.036 << " Kilometer per jam\n";
    cout << cm_per_second << " Centimeter per detik = " << cm_per_second * 0.01 << " Meter per detik\n";
    cout << cm_per_second << " Centimeter per detik = " << cm_per_second * 0.0223694 << " Mil per jam\n";
}

// Function to convert Meter per second to other units
void m_per_second_to_other(double m_per_second) {
    cout << m_per_second << " Meter per detik = " << m_per_second * 3.6 << " Kilometer per jam\n";
    cout << m_per_second << " Meter per detik = " << m_per_second * 100 << " Centimeter per detik\n";
    cout << m_per_second << " Meter per detik = " << m_per_second * 2.23694 << " Mil per jam\n";
}

// Function to convert Miles per hour to other units
void miles_per_hour_to_other(double miles_per_hour) {
    cout << miles_per_hour << " Mil per jam = " << miles_per_hour * 1.60934 << " Kilometer per jam\n";
    cout << miles_per_hour << " Mil per jam = " << miles_per_hour * 44.7 << " Centimeter per detik\n";
    cout << miles_per_hour << " Mil per jam = " << miles_per_hour * 0.44704 << " Meter per detik\n";
}

// Function for user login
bool login() {
    string nama, nim;
    cout <<"==== SELAMAT DATANG ====" <<endl;
    cout << "Masukkan Nama Anda: ";
    cin >> nama;
    cout << "Masukkan NIM Anda: ";
    cin >> nim;
    return (nama == "Fathir" && nim == "057"); //Nama dan Nim yang benar
}

int main() {
    int jumlah_login_salah = 0;
    char ulangi;

    do {
        bool berhasil_login = login();
        if (berhasil_login) {
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Nama atau NIM yang anda masukkan salah!" << endl;
            jumlah_login_salah++;
            if (jumlah_login_salah == 3) {
                cout << "Anda sudah 3 kali salah login. Program berhenti." << endl;
                return 0;
            }
        }
        cout << "Apakah Anda ingin mencoba login lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    do {
        int choice;
        double value;
        cout << "=========== Menu ============\n";
        cout << "1. Konversi Kilometer per jam\n";
        cout << "2. Konversi Centimeter per detik\n";
        cout << "3. Konversi Meter per detik\n";
        cout << "4. Konversi Mil per jam\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan (1/2/3/4/5): ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan kecepatan dalam Kilometer per jam: ";
                cin >> value;
                km_per_hour_to_other(value);
                break;
            case 2:
                cout << "Masukkan kecepatan dalam Centimeter per detik: ";
                cin >> value;
                cm_per_second_to_other(value);
                break;
            case 3:
                cout << "Masukkan kecepatan dalam Meter per detik: ";
                cin >> value;
                m_per_second_to_other(value);
                break;
            case 4:
                cout << "Masukkan kecepatan dalam Mil per jam: ";
                cin >> value;
                miles_per_hour_to_other(value);
                break;
            case 5:
                cout << "Program Berhenti\n";
                return 0;
            default:
                cout << "Pilihan tidak valid\n";
        }

        cout << "Apakah Anda ingin melakukan konversi lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    return 0;
}
