#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a && 1 <= b && 1 <= c &&
        a <= 100 && b <= 100 && c <= 100;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ac(integer a, integer c) = a + c;

    lemma min_sum_bound:
        \forall integer a, b, c;
        is_valid_params(a, b, c) ==>
        (sum_ab(a, b) <= a + b + c) &&
        (sum_bc(b, c) <= a + b + c) &&
        (sum_ac(a, c) <= a + b + c);
*/

/*@
    requires is_valid_params(a, b, c);
    ensures \result == a + b || \result == b + c || \result == a + c;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_ab;
    int min_bc;
    int min_ac;
    int temp;

    min_ab = a + b;
    min_bc = b + c;
    min_ac = a + c;

    //@ assert min_ab == sum_ab(a, b);
    //@ assert min_bc == sum_bc(b, c);
    //@ assert min_ac == sum_ac(a, c);

    if (min_ab > min_bc)
    {
        temp = min_ab;
        min_ab = min_bc;
        min_bc = temp;
    }

    if (min_bc > min_ac)
    {
        temp = min_bc;
        min_bc = min_ac;
        min_ac = temp;
    }

    if (min_ac > min_ab)
    {
        temp = min_ac;
        min_ac = min_ab;
        min_ab = temp;
    }

    //@ assert min_ab <= a + b + c;

    return min_ab;
}
