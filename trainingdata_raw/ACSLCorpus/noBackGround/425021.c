#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) == (b) || (a) == (c) || (b) == (c)) ? 2 : 3);
*/
uint32_t count_unique_colors(int64_t a, int64_t b, int64_t c)
{
    uint32_t num_colors;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a == b && b == c) {
        num_colors = 1;
    } else if (a == b || a == c || b == c) {
        num_colors = 2;
    } else {
        num_colors = 3;
    }
    
    //@ assert num_colors == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (a) == (c) || (b) == (c)) ? 2 : 3);
    //@ assert num_colors >= 1 && num_colors <= 3;
    
    return num_colors;
}
