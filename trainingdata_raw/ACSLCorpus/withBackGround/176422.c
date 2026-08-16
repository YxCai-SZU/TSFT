#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 == 1;
    logic integer half_plus_one(integer n) = n / 2 + 1;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == (n % 2 == 0 && n / 2 >= k) || (n % 2 == 1 && n / 2 + 1 >= k);
*/
bool func(int n, int k) {
    int half_n;
    bool res;

    half_n = n / 2;

    if (n % 2 == 0) {
        //@ assert n % 2 == 0;
        res = half_n >= k;
    } else {
        //@ assert n % 2 == 1;
        res = half_n + 1 >= k;
    }

    return res;
}
