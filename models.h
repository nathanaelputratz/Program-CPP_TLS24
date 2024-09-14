#include <vector>

vector<float> linear_regression(vector<float> x, vector<float> y) {
    /*
        Arguments:
        =============
        x: vector<float>
            data vektor yang berisikan bilangan rill (sebagai variabel independen)

        x: vector<float>
            data vektor yang berisikan bilangan rill (sebagai variabel dependen)

        Return:
        =============
        coef_: vector<float>
            data vektor yang berisikan slope dan intercept pada persamaan regresi linear
    */

    float covar = covariance(x, y); // menghitung covariance antara data x dan data y
    float var = variance(x); // menghitung variance data x
    float slope = covar/var; // menghitung slope
    float x_avg = average(x); // menghitung rata-rata data x
    float y_avg = average(y); // menghitung rata-rata data y
    float intercept = y_avg - x_avg * slope; // menghitung intercept
    vector<float> coef_ = {slope, intercept}; // deklarasi nilai coefficient
    return coef_;
}