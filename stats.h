#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

float average(vector<float> data) { 
    /*
        Desc: Menghitung rata-rata dari sebuah data

        Arguments:
        =============
        data: vector<float>
            Data yang berisikan bilangan rill

        Return:
        =============
        average: float
            Rata-rata dari data
    */

    float average = 0;
    for (float i : data) average += i; // Looping penjumlahan tiap nilai pada data
    average /= data.size(); // Membagi hasil penjumlahan dengan jumlah data
    return average;
}

float median(vector<float> data) {
    /*
        Desc: Menghitung median dari sebuah data

        Arguments:
        =============
        data: vector<float>
            Data yang berisikan bilangan rill

        Return:
        =============
        median: float
            Median dari data
    */
    sort(data.begin(), data.end()); // sorting data median
    if (data.size() & 1) { // Conditional statement apabila jumlah data ganjil
        float median = data[data.size()/2];
        return median;
    } else {
        float median = (data[data.size()/2] + data[data.size()/2 + 1]) / 2;
        return median;
    }
}

float variance(vector<float> data, bool isSample = false) {
    /*
        Desc: Menghitung variansi dari sebuah data

        Arguments:
        =============
        data: vector<float>
            Data yang berisikan bilangan rill
        
        isSample: bool
            Untuk mengetahui apakah data yang di-input sebagai data sampel atau populasi

        Return:
        =============
        var: float
            Variansi dari data
    */

    float sum = 0;
    float avg = average(data); // Mencari nilai rata-rata dengan fungsi average
    for (float i : data) { // Looping penjumlahan data ke-i dikurang dengan rata-rata
        sum += (i - avg)*(i - avg);
    }

    if (isSample) { // Conditional statement apakah data merupakan sampel atau populasi
        float var = sum/(data.size() - 1);
        return var;
    } else {
        float var = sum / data.size(); 
        return var;
    }
}

float covariance(vector<float> data1, vector<float> data2, bool isSample = false) {
    /*
        Desc: Menghitung covariance dari dua buah data

        Arguments:
        =============
        data1: vector<float>
            Data yang berisikan bilangan rill (sebagai variabel independen)
        
        data2: vector<float>
            Data yang berisikan bilangan rill (sebagai variabel dependen)

        isSample: bool
            Untuk mengetahui apakah data yang di-input sebagai data sampel atau populasi

        Return:
        =============
        covar: float
            Variansi dari data
    */
    float sum = 0;
    float avg_1 = average(data1); // Mencari nilai rata-rata dari fungsi average untuk data 1
    float avg_2 = average(data2); // Mencari nilai rata-rata dari fungsi average untuk data 2

    for (int i = 0; i < data1.size(); i++) { // Looping penjumlahan data ke-i dikurang dengan rata-rata
        sum += (data1[i] - avg_1)*(data2[i] - avg_2);
    }

    if (isSample) {  // Conditional statement apakah data merupakan sampel atau populasi
        float covar = sum/(data1.size() - 1);
        return covar;
    } else {
        float covar = sum/data1.size();
        return covar;
    }
}

float stdev(vector<float> data, bool isSample = false) {
    /*
        Desc: Menghitung standar deviasi dari sebuah data

        Arguments:
        =============
        data: vector<float>
            Data yang berisikan bilangan rill (sebagai variabel independen)

        isSample: bool
            Untuk mengetahui apakah data yang di-input sebagai data sampel atau populasi

        Return:
        =============
        std: float
            Standar deviasi dari data
    */
    float std = sqrt(variance(data, isSample)); // akar dari variansi data
    return std;
}

float mode(vector<float> data) {
    /*
        Desc: Menghitung modus dari sebuah data
        
        Arguments:
        =============
        data: vector<float>
            Data yang berisikan bilangan rill (sebagai variabel independen)

        Return:
        =============
        mode: float
            modus dari data
    */

    sort(data.begin(), data.end()); // sorting pada data

    float mode = data[0];
    int max_freq = 1;
    int curr_freq = 1;
    float curr_val = data[0];

    for (size_t i = 1; i < data.size(); ++i) { // looping untuk mencari nilai modus
        if (data[i] == curr_val) { // conditional statement apakah data ke-i sama dengan data sebelumnya
            curr_freq++;
        } else {
            if (curr_freq > max_freq) { // conditional statement apakah nilai frekuensi sebelumnya lebih besar dari nilai frekuensi data modus sebelumnya
                max_freq = curr_freq;
                mode = curr_val;
            }
            curr_val = data[i];
            curr_freq = 1;
        }
    }

    if (curr_freq > max_freq) { // conditional statement apakah nilai frekuensi sebelumnya lebih besar dari nilai frekuensi data modus sebelumnya
        mode = curr_val;
    }

    return mode;
}