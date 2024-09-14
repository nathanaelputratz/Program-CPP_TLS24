#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include <functional>

using namespace std;

vector<string> column_name = {}; // global variabel nama kolom

void show_columns() {
    /*
        Desc: Menampilkan kolom pada data yang telah di load

        Arguments:
        =============

        Return:
        =============
        
    */

    system("cls"); // Menghapus tampilan pada terminal atau console
    if (column_name.size() == 0) { // Mengecek apakah ada data yang sudah di load
        cout << "No Data Inputed" << "\n";
    }
    string a;
    for (string col : column_name) { // Looping untuk print nilai kolom pada data yang sudah di load
        cout << col << "\n";
    }
    cout << "Input Anything to Close : ";
    cin >> a;
    cout << "\n";
}

map<string, vector<float>> read_csv(string file_path) {
    /*
        Desc: Menampilkan kolom pada data yang telah di load

        Arguments:
        =============
        file_path: string
            file path pada data yang akan di load (csv)

        Return:
        =============
        m: map<string, vector<float>>
            map yang berisikan data csv
    */

    map<string, vector<float>> m;
    ifstream file(file_path);
    vector<string> columns_;
    bool col_names=true;

    if (!file.is_open()) { // Cek apakah file dibuka oleh aplikasi lain atau tidak
        cerr << "Error: Could not open the file " << file_path << "\n";
        return m;
    }

    string line;
    while (getline(file, line)) { // Looping untuk mengambil data pada file csv per line
        string field;
        stringstream ss(line);
        if (col_names) { // Conditional statement untuk menentukan apakah data termasuk nama kolom atau tidak
            vector<string> fields;
            col_names = false;
            while (getline(ss, field, ',')) { // Looping untuk mengambil data per ',' (comma sebagai delimiter pada file csv)
                fields.push_back(field); // Memasukan data kedalam vektor fields
            }
            columns_ = fields;
            for (string f : fields) { // Looping untuk memasukan data pada map untuk tiap kolom
                vector<float> a = {};
                m.insert(make_pair(f, a));
            }
        } else {
            vector<float> fields;
            while (getline(ss, field, ',')) { // Looping untuk mengambil data per ',' (comma sebagai delimiter pada file csv)
                fields.push_back(stof(field)); // Type casting variabel field dari string menjadi float dengan fungsi stof dan memasukannya dalam vektor fields
            }
            for (int i = 0; i < fields.size(); i++) { // Looping untuk memasukan data pada fields kedalam kolom pada tiap map
                m[columns_[i]].push_back(fields[i]);
            }
        }
    }
    column_name = columns_;
    file.close(); // close file csv
    return m;
}