#include <stdint.h>

/*@
    requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    ensures \result <= 3 && \result >= 0;
*/
uint32_t count_triangulars(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t count = 0;
    
    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;
    
    if (a + b > c) {
        count += 1;
    }
    if (a + c > b) {
        count += 1;
    }
    if (b + c > a) {
        count += 1;
    }
    
    //@ assert count <= 3;
    return count;
}
