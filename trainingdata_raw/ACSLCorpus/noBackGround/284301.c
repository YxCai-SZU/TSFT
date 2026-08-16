#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20);
    requires (1 <= (m) <= 20);
    ensures (n == m ==> \result == n + m);
    ensures (n != m ==> \result == 2 * (((n) > (m)) ? (n) : (m)) - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_n_m;
    int min_n_m;
    int result;

    // Calculate max manually
    if (n > m) {
        max_n_m = n;
    } else {
        max_n_m = m;
    }

    // Calculate min manually
    if (n < m) {
        min_n_m = n;
    } else {
        min_n_m = m;
    }

    if (n == m) {
        //@ assert n == m;
        result = n + m;
        return result;
    } else {
        //@ assert n != m;
        //@ assert max_n_m == (((n) > (m)) ? (n) : (m));
        result = 2 * max_n_m - 1;
        return result;
    }
}
