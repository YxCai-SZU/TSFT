#include <stdbool.h>

/*@ requires (1 <= (x) <= 100000);
    ensures \result == (x >= 2000 || x % 200 == 0);
*/
bool func(unsigned long long x)
{
    // Variable declarations at scope top
    unsigned long long n;
    unsigned long long remainder;
    unsigned long long i;

    //@ assert (1 <= (x) <= 100000);
    n = x / 200;
    remainder = x;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant remainder == x - 200 * i;
        loop assigns i, remainder;
    */
    while (i < n) {
        //@ assert remainder >= 200;
        remainder -= 200;
        i += 1;
    }

    //@ assert remainder == x % 200;
    return (remainder == 0) || (x >= 2000);
}
