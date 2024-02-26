#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int precision = 1000000; // number of decimal places to generate
    int digits_per_iteration = 14; // digits of Pi to generate per iteration

    mpf_set_default_prec(precision * 4); // set precision of mpf_t variables

    mpf_t pi, a, b, c, d, e, f, g, h, k;
    mpf_init_set_ui(pi, 0);
    mpf_init_set_ui(a, 1);
    mpf_init_set_ui(b, 1);
    mpf_init_set_ui(c, 13591409);
    mpf_init_set_ui(d, 545140134);
    mpf_init_set_ui(e, 640320);
    mpf_init_set_ui(f, 100100025);
    mpf_init_set_ui(g, 327843840);
    mpf_init_set_ui(h, 53360);
    mpf_init_set_ui(k, 12);

    for (int i = 0; i < precision / digits_per_iteration + 1; i++) {
        mpf_mul(pi, a, b);
        mpf_mul_ui(pi, pi, 53360);
        mpf_add_ui(pi, pi, 13591409);
        mpf_mul(pi, pi, c);
        mpf_div(pi, pi, d);
        mpf_add_ui(c, c, 545140134);
        mpf_mul_ui(d, d, 640320);
        mpf_pow_ui(e, e, 3);
        mpf_mul(e, e, f);
        mpf_add(e, e, g);
        mpf_mul(e, e, h);
        mpf_div(k, k, 12);
        mpf_pow_ui(k, k, 4);
        mpf_mul(e, e, k);
        mpf_div(pi, pi, e);

        if (i == 0) {
            cout << "3.";
        } else {
            cout << setfill('0') << setw(digits_per_iteration) << (long) (mpf_get_d(pi) * pow(10, digits_per_iteration)) << flush;
        }

        mpf_mul_ui(a, a, 6 * i + 5);
        mpf_mul_ui(a, a, 2 * i + 1);
        mpf_mul_ui(b, b, 6 * i + 1);
        mpf_mul_ui(b, b, 2 * i + 1);
    }

    return 0;
}

