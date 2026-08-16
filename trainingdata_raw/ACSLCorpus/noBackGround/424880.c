#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == a * b || \result == b * c || \result == c * a;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    // Variable declarations at scope top
    int64_t max_ab;
    int64_t max_result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert a * b <= 10000;
    //@ assert b * c <= 10000;
    //@ assert c * a <= 10000;

    if (a * b > b * c) {
        max_ab = a * b;
    } else {
        max_ab = b * c;
    }

    if (max_ab > c * a) {
        max_result = max_ab;
    } else {
        max_result = c * a;
    }

    //@ assert max_result == a * b || max_result == b * c || max_result == c * a;
    //@ assert max_result >= 0;
    
    return max_result;
}
