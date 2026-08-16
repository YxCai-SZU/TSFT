#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at scope top
    int64_t s1;
    int64_t s2;
    int64_t res;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert 1 <= ((a) * (b)) <= 100000000;
    //@ assert 1 <= ((c) * (d)) <= 100000000;
    
    s1 = a * b;
    s2 = c * d;
    
    //@ assert s1 == ((a) * (b));
    //@ assert s2 == ((c) * (d));
    
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
