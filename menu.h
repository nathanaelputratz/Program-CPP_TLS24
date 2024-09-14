#include <iostream>
#include <string>

using namespace std;

int open_menu() {
    /*
        Desc: Menampilkan menu saat user menggunakan program

        Arguments:
        =============

        Return:
        =============
        a: int
            Nilai inputan untuk menu yang dipilih user
    */

    int a;
    do { // do while untuk menampilkan menu terlebih dahulu
        system("cls");
        cout << "==== [WELCOME TO MENU] ====" << "\n";
        cout << "[1] Input Data" << "\n";
        cout << "[2] Show Columns" << "\n";
        cout << "[3] Edit Columns" << "\n";
        cout << "[4] Descriptive Statistics" << "\n";
        cout << "[5] Linear Regression" << "\n";
        cout << "[6] Exit" << "\n";
        cout << "===========================" << "\n";
        cout << "Please input a number between the range of [1-6] : ";
        cin >> a; // input data
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // untuk mengabaikan sisa baris sebelumnya
    } while (a < 1 || a > 6); // conditional statement apakah data berada di rentang 1 < a < 6 atau diluar itu
    
    return a;
}

int desc_stats(string table_1, string table_2) {
    /*
        Desc: Menampilkan menu saat user memilih menu Descriptive Statistics

        Arguments:
        =============
            table_1: string
                Berisikan nama kolom pada tabel pertama

            table_2: string
                Berisikan nama kolom pada tabel kedua

        Return:
        =============
        a: int
            Nilai inputan untuk menu yang dipilih user
    */
    int a;
    do { // do while untuk menampilkan menu terlebih dahulu
        system("cls"); // menghapus tampilan pada konsol atau terminal
        cout << "Table 1 : [" << table_1 << "]" << "\n";
        cout << "Table 2 : [" << table_2 << "]" << "\n";
        cout << "===========================" << "\n";
        cout << "[1] Average" << "\n";
        cout << "[2] Median" << "\n";
        cout << "[3] Mode" << "\n";
        cout << "[4] Variance" << "\n";
        cout << "[5] Covariance" << "\n";
        cout << "[6] Standard Deviation" << "\n";
        cout << "[7] Back" << "\n";
        cout << "===========================" << "\n";
        cout << "Please input a number between the range of [1-7] : ";
        cin >> a; // input data
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // untuk mengabaikan sisa baris sebelumnya
    } while (a < 1 || a > 7); // conditional statement apakah data berada di rentang 1 < a < 7 atau diluar itu
    
    return a;
}

int desc_stats_table(string table_1, string table_2) {
    /*
        Desc: Menampilkan menu saat user diminta menginput antara memilih tabel 1 atau tabel 2

        Arguments:
        =============
            table_1: string
                Berisikan nama kolom pada tabel pertama

            table_2: string
                Berisikan nama kolom pada tabel kedua
                
        Return:
        =============
        a: int
            Nilai inputan untuk menu yang dipilih user
    */
   
    int a;
    do { // do while untuk menampilkan menu terlebih dahulu
        system("cls"); // menghapus tampilan pada konsol atau terminal
        cout << "Table 1 : [" << table_1 << "]" << "\n";
        cout << "Table 2 : [" << table_2 << "]" << "\n";
        cout << "===========================" << "\n";
        cout << "Choose between \n [1] Table 1 and [2] Table 2" << "\n";
        cout << "Please input a number between the range of [1-2] : ";
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // untuk mengabaikan sisa baris sebelumnya
    } while (a < 1 || a > 2); // conditional statement apakah data berada di rentang 1 < a < 2 atau diluar itu
    
    return a;
}