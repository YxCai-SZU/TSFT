#include <stddef.h>

/*@
    requires (3 <= (a) <= 20);
    requires (3 <= (b) <= 20);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= a + b;
    ensures \result >= b * 2 - 1;
    ensures \result >= a * 2 - 1;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t max_ab;
    size_t max_2a_2b;
    size_t max_sum;

    max_ab = (a > b) ? a : b;
    //@ assert max_ab == (a > b ? a : b);

    max_2a_2b = (a * 2 > b * 2) ? a * 2 : b * 2;
    //@ assert max_2a_2b == (a * 2 > b * 2 ? a * 2 : b * 2);

    max_sum = (a + b > max_2a_2b - 1) ? a + b : max_2a_2b - 1;
    //@ assert max_sum == (((a) + (b)) > (((a) * 2) > ((b) * 2) ? ((a) * 2) : ((b) * 2)) - 1 ?         ((a) + (b)) :         ((((a) * 2) > ((b) * 2) ? ((a) * 2) : ((b) * 2)) - 1));

    return max_sum;
}
