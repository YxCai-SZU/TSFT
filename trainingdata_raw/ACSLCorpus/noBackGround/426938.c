#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    unsigned int sum = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant sum == (500 * (i));
        loop invariant (1 <= (k) <= 100 && 1 <= (x) <= 100000);
        loop assigns sum, i;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert sum <= 4294967195; // UINT_MAX - 500
        //@ assert (500 * (i)) <= 50000;
        sum += 500;
        i += 1;
    }
    return sum >= x;
}
