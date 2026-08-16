#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures 1 <= \result && \result <= 3;
    assigns \nothing;
*/
unsigned int count_unique_colors(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int num_colors;

    if (a == b && b == c) {
        num_colors = 1;
    } else if (a == b || a == c || b == c) {
        num_colors = 2;
    } else {
        //@ assert 1 <= 3 && 3 <= 3;
        num_colors = 3;
    }

    return num_colors;
}
