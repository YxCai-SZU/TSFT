#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations at scope top
    uint32_t s1;
    uint32_t s2;
    uint32_t res;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((a) * (b)) <= 10000 * 10000;
    s1 = a * b;

    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) >= 1;
    //@ assert ((c) * (d)) <= 10000 * 10000;
    s2 = c * d;

    //@ assert s1 >= 1;
    //@ assert s2 >= 1;
    if (s1 > s2) {
        res = s1;
        //@ assert res == ((a) * (b));
    } else {
        res = s2;
        //@ assert res == ((c) * (d));
    }

    //@ assert res >= 1;
    return res;
}
