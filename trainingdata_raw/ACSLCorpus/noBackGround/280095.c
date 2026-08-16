#include <stddef.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t h)
{
    // Variable declarations at scope top
    size_t sum;
    size_t res;

    // Precondition assertions
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= h <= 100;
    //@ assert h % 2 == 0;

    sum = a + b;
    //@ assert sum <= 200;

    //@ assert sum * h <= 20000;
    res = sum * h / 2;

    // Postcondition verification
    //@ assert res == (((a) + (b)) * (h) / 2);
    return res;
}
