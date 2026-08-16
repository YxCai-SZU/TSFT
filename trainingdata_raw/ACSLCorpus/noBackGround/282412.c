#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t x;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((a) * (b)) <= 10000;

    x = a * b;
    //@ assert x == ((a) * (b));

    return x;
}
