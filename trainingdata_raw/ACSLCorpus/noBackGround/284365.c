#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at scope top
    int64_t res;
    
    // Precondition assertions
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    // Multiplication safety bounds
    //@ assert ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) <= 100000000;
    
    if (a * b > c * d) {
        res = a * b;
    } else {
        res = c * d;
    }
    
    // Postcondition verification
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= ((a) * (b));
    //@ assert res >= ((c) * (d));
    
    return res;
}
