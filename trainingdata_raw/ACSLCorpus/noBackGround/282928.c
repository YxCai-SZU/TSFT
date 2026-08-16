#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == ((n / 100) * 100 + (n / 10) % 10 * 10 + (n % 100) % 10 >= n);
*/
bool func(int n) {
    int n_div_100;
    int n_mod_100;
    int n_mod_10;
    int sum;
    bool result;

    n_div_100 = n / 100;
    n_mod_100 = n % 100;
    n_mod_10 = n_mod_100 % 10;
    sum = n_div_100 * 100 + (n_mod_100 / 10) * 10 + n_mod_10;

    result = false;
    if (sum >= n) {
        result = true;
    }

    //@ assert result == (sum >= n);

    return result;
}
