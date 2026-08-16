#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    requires (1 <= (a) <= 100);
    ensures \result == true <==> (((n) * (m)) / 2) >= a;
*/
bool func(unsigned long n, unsigned long m, unsigned long a)
{
    // Variable declarations at scope top
    unsigned long max;
    bool result;

    // Preconditions prevent overflow
    //@ assert n <= 100;
    //@ assert m <= 100;
    //@ assert n * m <= 10000;

    max = (n * m) / 2;

    if (a <= max) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
