#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result >= a && \result >= b && \result >= c;
    ensures \result == a || \result == b || \result == c;
    assigns \nothing;
*/
int max_sum(int a, int b, int c)
{
    // Variable declarations at scope top
    int max_ab;
    int result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);

    max_ab = (a > b) ? a : b;
    result = (max_ab > c) ? max_ab : c;

    //@ assert result >= a;
    //@ assert result >= b;
    //@ assert result >= c;
    //@ assert result == a || result == b || result == c;

    return result;
}
