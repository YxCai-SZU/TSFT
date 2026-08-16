#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    requires 1 <= g <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (r == g && g == b);
    ensures \result == 2 ==> ((r == g && g != b) || (r == b && r != g) || (g == b && g != r));
    ensures \result == 3 ==> (r != g && g != b && r != b);
*/
uint32_t count_unique_colors(uint32_t r, uint32_t g, uint32_t b)
{
    uint32_t count;
    
    //@ assert (1 <= (r) <= 100) && (1 <= (g) <= 100) && (1 <= (b) <= 100);
    
    if (r == g && g == b) {
        //@ assert r == g && g == b;
        count = 1;
    } else if (r == g || g == b || r == b) {
        //@ assert (r == g && g != b) || (r == b && r != g) || (g == b && g != r);
        count = 2;
    } else {
        //@ assert r != g && g != b && r != b;
        count = 3;
    }
    
    //@ assert count == (((r) == (g) && (g) == (b)) ? 1 :         ((r) == (g) || (g) == (b) || (r) == (b)) ? 2 :         3);
    return count;
}
