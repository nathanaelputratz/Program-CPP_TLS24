# Program-CPP_TLS24
Nama         : Nathanael Satya Saputra <br />
Kelompok     : Fourier

-----
**Judul        : Kalkulator Statistika Sederhana** <br />
Deskripsi      : <br />

Program Kalkulator Statistika Sederhana dirancang untuk mempermudah user dalam melakukan perhitungan statistika dasar seperti rata-rata, median, modus dan perhitungan lainnya dengan cepat dan akurat. Program ini juga dirancang untuk dapat membaca file csv atau comma separated value sehingga memudahkan pengguna untuk mengimport data untuk perhitungan statistika dasar.

---
**Menu Program**
Dalam program ini terdiri dari beberapa menu seperti:
- Input Data <br /> 
  Data yang dapat di inputkan hanya berupa data csv atau comma separated value.
- Show Columns <br />
  Menampilkan nama kolom pada tiap data.
- Edit Columns <br />
  Melakukan edit pada nama kolom. <br />
  **Perlu dicatat bahwa menu diatas tidak mengubah nama kolom pada data namun hanya mengubah nama kolom yang akan dijadikan input untuk pemrosesan data!**
- Descriptive Statistics
  -  Average<br />
     Menghitung rata-rata dari data yang dipilih. <br />
     ```math
     average \ = \ \sum_{i = 1}^{n} \frac{x_i}{n}
     ```
  -  Median<br />
     Menghitung median dari data yang dipilih. <br />
     Untuk jumlah data ganjil <br />
     ```math
     median \ = \ x_{\frac{n + 1}{2}}
     ```
     Untuk jumlah data genap <br />
     ```math
     median \ = \frac{\ x_{\frac{n}{2}} + x_{\frac{n}{2} + 1}}{2}
     ```
  -  Mode<br />
     Menghitung modus dari data yang dipilih.
  -  Variance<br />
     Menghitung variansi dari data yang dipilih. 
     ```math
     var(x) \ = \ \sum_{i = 1}^{n} \frac{(x_{i} - \bar{x})^{2}}{n}
     ```
  -  Covariance<br />
     Menghitung covariance dari data yang dipilih.
     ```math
     covar(x, y) \ = \ \sum_{i = 1}^{n} \frac{(x_{i} - \bar{x})(y_{i} - \bar{y})}{n}
     ```
  -  Standard Deviation<br />
     Menghitung standar deviasi dari data yang dipilih.
     ```math
     std(x) \ = \sqrt{var(x)}
     ```
  -  Back<br />
     Kembali menuju menu utama
- Linear Regression<br />
  Dalam program ini digunakan metode least square untuk menghitung slope dan intercept pada regresi linear.
  ```math
     y \ = \beta_{1} x + \beta_{0}
  ```
  ```math
     \beta_{1} \ = \frac{covar(x, y)}{var(x)}
  ```
  ```math
     \beta_{0} \ = \bar{y} - \beta_{1} \bar{x}
  ```
- Exit
-----

Untuk melakukan compile pada file cpp diatas dapat menggunakan command
```
g++ *.cpp -o Main.exe
```
pada terminal atau command prompt

Untuk menjalankan program pada terminal atau command prompt dapat langsung di klik atau menggunakan command (pastikan file Main.exe berada di directory yang sama)
```
./Main.exe
```
