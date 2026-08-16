#include <stdint.h>

/*@
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result <= 3 && \result >= 0;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 2 ==> (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)));
    ensures \result == 0 ==> ((a) != (b) && (b) != (c) && (c) != (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t count = 0;
    
    //@ assert a <= 100 && b <= 100 && c <= 100;
    
    if (a == b) {
        count += 1;
        //@ assert a == b;
    }
    if (b == c) {
        count += 1;
        //@ assert b == c;
    }
    if (c == a) {
        count += 1;
        //@ assert c == a;
    }
    
    //@ assert count <= 3;
    
    if (count == 3) {
        //@ assert ((a) == (b) && (b) == (c));
        return 1;
    } else if (count == 2 || count == 1) {
        //@ assert (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)));
        return 2;
    } else {
        //@ assert ((a) != (b) && (b) != (c) && (c) != (a));
        return 0;
    }
}
