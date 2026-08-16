#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures 1 <= \result && \result <= 3;
    ensures \result == ((a) == (b) && (b) == (c) ? 1 :
        (a) == (b) || (b) == (c) || (a) == (c) ? 2 :
        3);
*/
unsigned int count_unique_colors(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int num_colors;
    
    if (a == b && b == c) {
        num_colors = 1;
    } else if (a == b || b == c || a == c) {
        num_colors = 2;
    } else {
        num_colors = 3;
    }
    
    //@ assert 1 <= num_colors && num_colors <= 3;
    //@ assert num_colors == ((a) == (b) && (b) == (c) ? 1 :         (a) == (b) || (b) == (c) || (a) == (c) ? 2 :         3);
    
    return num_colors;
}
