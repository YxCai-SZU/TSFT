#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t read(int32_t n, int32_t m)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert n >= 2 && n <= 100;
    //@ assert m >= 2 && m <= 100;
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert m - 1 >= 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 9801;
    //@ assert (n - 1) * (m - 1) >= 1;

    result = (n - 1) * (m - 1);
    return result;
}
