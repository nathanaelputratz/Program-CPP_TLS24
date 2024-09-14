#include "stats.h"
#include "read_csv.h"
#include "menu.h"
#include "models.h"
#include <iostream>

// Import beberapa file header dan library iostream 

using namespace std;

int main() {
    int input = -1; // Deklarasi nilai input
    map<string, vector<float>> data; // Deklarasi variabel map data
    string table_1, table_2, close; // Deklarasi variabel table_1, table_2, dan close
    
    string fpath;
    cout << "Input file path : ";
    getline(cin, fpath); // Mengambil data file path
    cout << "\n";
    cout << "Choose Table 1 [Columns] : ";
    getline(cin, table_1); // Mengambil data nama kolom pertama yang dipilih user
    cout << "\n";
    cout << "Choose Table 2 [Columns] : ";
    getline(cin, table_2); // Mengambil data nama kolom kedua yang dipilih user
    cout << "\n";
    data = read_csv(fpath); // Pengambilan data csv menggunakan fungsi read_csv

    while (input != 6) { // Looping dengan conditional statement selama input tidak bernilai 6 (6 -> exit)
        input = open_menu(); // Mengambil input dan menampilkan menu melalui fungsi open_menu 
        if (input == 1) { // Conditional statement apabila user memilih input 1
            string fpath;
            cout << "Input file path : ";
            getline(cin, fpath); // Mengambil data file path
            cout << "\n";
            cout << "Choose Table 1 [Columns] : ";
            getline(cin, table_1); // Mengambil data nama kolom pertama yang dipilih user
            cout << "\n";
            cout << "Choose Table 2 [Columns] : ";
            getline(cin, table_2); // Mengambil data nama kolom kedua yang dipilih user
            cout << "\n";

            data = read_csv(fpath); // Pengambilan data csv menggunakan fungsi read_csv
        } else if (input == 2) { // Conditional statement apabila user memilih input 2
            show_columns(); // Menampilkan kolom yang ada pada data
        } else if (input == 3) { // Conditional statement apabila user memilih input 3 untuk mengubah nama tabel_1 dan tabel_2
            cout << "Choose Table 1 [Columns] : ";
            getline(cin, table_1); // Mengambil nilai baru untuk tabel_1
            cout << "\n";
            cout << "Choose Table 2 [Columns] : ";
            getline(cin, table_2); // Mengambil nilai baru untuk tabel_2
            cout << "\n";
        } else if (input == 4) { // Conditional statement apabila user memilih input 4 untuk menu descriptive statistics
            int desc_input = desc_stats(table_1, table_2);  // Mengambil nilai input dan menampilkan menu descriptive statistics
            if (desc_input == 1) { // Conditional statement apabila user memilih input 1 (Average)
                cout << "Average" << "\n";
                int desc_input_a = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dirata-rata
                system("cls");
                if (desc_input_a == 1) { // Conditional statement untuk nilai kolom tabel yang dirata-rata
                    cout << "Average : " << average(data[table_1]) << "\n";
                } else {
                    cout << "Average : " << average(data[table_2]) << "\n";
                }
                cout << "Input Anything to Close : ";
                cin >> close;
            } else if (desc_input == 2) { // Conditional statement apabila user memilih input 2 (Median)
                cout << "Median" << "\n";
                int desc_input_a = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dicari mediannya
                system("cls");
                if (desc_input_a == 1) { // Conditional statement untuk nilai kolom tabel yang dicari mediannya
                    cout << "Median : " << median(data[table_1]) << "\n";
                } else {
                    cout << "Median : " << median(data[table_2]) << "\n";
                }
                cout << "Input Anything to Close : ";
                cin >> close;
            } else if (desc_input == 3) { // Conditional statement apabila user memilih input 3 (Mode)
                cout << "Mode" << "\n";
                int desc_input = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dicari modusnya
                system("cls");
                if (desc_input == 1) { // Conditional statement untuk nilai kolom tabel yang dicari modusnya
                    cout << "Mode : " << mode(data[table_1]) << "\n";
                } else {
                    cout << "Mode : " << mode(data[table_2]) << "\n";
                }
                cout << "Input Anything to Close : ";
                cin >> close;
            } else if (desc_input == 4) { // Conditional statement apabila user memilih input 4 (Variance)
                cout << "Variance" << "\n";
                int desc_input = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dicari variansi
                system("cls");
                if (desc_input == 1) { // Conditional statement untuk nilai kolom tabel yang dicari variansinya
                    cout << "Variance : " << variance(data[table_1]) << "\n";
                } else {
                    cout << "Variance : " << variance(data[table_2]) << "\n";
                }
                cout << "Input Anything to Close : ";
                cin >> close;
            } else if (desc_input == 5) { // Conditional statement apabila user memilih input 5 (Covariance)
                cout << "Covariance" << "\n";
                int desc_input_1 = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dicari covariance untuk data independen
                int desc_input_2 = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dicari covariance untuk data dependen

                system("cls");
                if (desc_input_1 == 1) { // Conditional statement untuk nilai kolom tabel yang dicari covariance
                    if (desc_input_2 == 1) { // Conditional statement untuk nilai kolom tabel yang dicari covariance pada data ke-2
                        cout << "Covariance : " << covariance(data[table_1], data[table_1]) << "\n";
                    } else {
                        cout << "Covariance : " << covariance(data[table_1], data[table_2]) << "\n";
                    }
                } else {
                    if (desc_input_2 == 1) { // Conditional statement untuk nilai kolom tabel yang dicari covariance pada data ke-2
                        cout << "Covariance : " << covariance(data[table_2], data[table_1]) << "\n";
                    } else {
                        cout << "Covariance : " << covariance(data[table_2], data[table_2]) << "\n";
                    }
                }
                cout << "Input Anything to Close : ";
                cin >> close;
            } else if (desc_input == 6) { // Conditional statement apabila user memilih input 6 (Standard Deviation)
                cout << "Standard Deviation" << "\n";
                int desc_input = desc_stats_table(table_1, table_2); // Mengambil input kolom tabel yang akan dicari standar deviasinya
                system("cls");
                if (desc_input == 1) { // Conditional statement untuk nilai kolom tabel yang dicari standar deviasinya
                    cout << "Standard Deviation : " << stdev(data[table_1]) << "\n";
                } else {
                    cout << "Standard Deviation : " << stdev(data[table_2]) << "\n";
                }
                cout << "Input Anything to Close : ";
                cin >> close;
            }
        } else if (input == 5) { // Conditional statement apabila user memilih input 5 untuk menu regresi linear (Linear Regression)
            system("cls");
            vector<float> coef_; // Deklarasi vektor koefisien
            cout << "Linear Regression" << "\n";
            cout << "Table 1 : [" << table_1 << "]" << "\n";
            cout << "Table 2 : [" << table_2 << "]" << "\n";
            cout << "\n";

            cout << "Input for independent table : ";
            int x_var;
            cin >> x_var; // input nilai variabel independen (x)
            cout << "Input for dependent table : ";
            int y_var;
            cin >> y_var; // input nilai variabel dependen (y)
            if (x_var == 1) { // conditional statement untuk variabel independen
                if (y_var == 1) { // conditional statement untuk variabel dependen
                    coef_ = linear_regression(data[table_1], data[table_1]); // mencari nilai koefisien dari fungsi linear_regression
                } else {
                    coef_ = linear_regression(data[table_1], data[table_2]); // mencari nilai koefisien dari fungsi linear_regression
                }
            } else {
                if (y_var == 1) { // conditional statement untuk variabel dependen
                    coef_ = linear_regression(data[table_2], data[table_1]); // mencari nilai koefisien dari fungsi linear_regression
                } else {
                    coef_ = linear_regression(data[table_2], data[table_2]); // mencari nilai koefisien dari fungsi linear_regression
                }
            }

            cout << "Slope      : " << coef_[0] << "\n"; // Menampilkan nilai slope
            cout << "Intercept  : " << coef_[1] << "\n"; // Menampilkan nilai intercept
            
            cout << "Input Anything to Close : ";
            cin >> close;
        }
    }
    system("cls"); // Clear console program selesai!
    return 0;
}
