#include <stdint.h>

/*@
    requires a != b;
    requires 1 <= a && a <= 3;
    requires 1 <= b && b <= 3;
    ensures \result >= 1 && \result <= 3;
    ensures \result != a;
    ensures \result != b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t res;
    
    //@ assert (1 <= (a) && (a) <= 3);
    //@ assert (1 <= (b) && (b) <= 3);
    //@ assert a != b;
    
    res = 6 - a - b;
    
    //@ assert (6 - (a) - (b)) == res;
    //@ assert 1 <= res && res <= 3;
    //@ assert res != a;
    //@ assert res != b;
    
    return res;
}
