#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long m) {
    bool result;
    //@ assert n == m ==> n == m;
    result = (n == m);
    return result;
}
