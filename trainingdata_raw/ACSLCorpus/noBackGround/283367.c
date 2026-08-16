#include <stdint.h>

/*@
    requires (1 <= (n) <= 200000 && 1 <= (k) <= (n));
    ensures \result >= 0;
    ensures \result <= n - 1;
*/
int64_t func(int64_t n, int64_t k) {
    int64_t m;
    int64_t i;
    int64_t n1;
    int64_t m1;
    int64_t ans;

    m = n - 1;
    i = 0;

    //@ ghost int64_t initial_n = n;
    //@ ghost int64_t initial_k = k;

    /*@
        loop invariant 0 <= i <= k - 1;
        loop invariant m == ((initial_n) - 1 - (i));
        loop invariant (1 <= (initial_n) <= 200000 && 1 <= (initial_k) <= (initial_n));
        loop assigns m, i;
    */
    while (i < k - 1) {
        //@ assert m == initial_n - 1 - i;
        m -= 1;
        i += 1;
        //@ assert m == initial_n - 1 - i;
    }

    //@ assert m >= 0 && m <= initial_n - 1;

    n1 = (n - 1 < 0) ? -(n - 1) : (n - 1);
    //@ assert n1 >= 0;

    m1 = (m < 0) ? -m : m;
    //@ assert m1 >= 0;

    ans = (n1 < m1) ? n1 : m1;
    //@ assert ans >= 0;
    //@ assert ans <= n - 1;

    return ans;
}
