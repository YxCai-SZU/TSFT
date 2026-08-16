#include <stdbool.h>

/*@
    predicate in_range(integer v) = 3 <= v <= 20;

    logic integer max_of_three(integer a, integer b) =
        (a + b > 2 * a - 1) ?
            ((a + b > 2 * b - 1) ? a + b : 2 * b - 1) :
            ((2 * a - 1 > 2 * b - 1) ? 2 * a - 1 : 2 * b - 1);

    lemma max_properties:
        \forall integer a, b;
            in_range(a) && in_range(b) ==>
            max_of_three(a, b) >= 0 &&
            max_of_three(a, b) <= 40 &&
            (max_of_three(a, b) == a + b ||
             max_of_three(a, b) == 2 * a - 1 ||
             max_of_three(a, b) == 2 * b - 1);
*/

/*@
    requires in_range(a);
    requires in_range(b);
    ensures \result >= 0;
    ensures \result <= 40;
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
*/
int func(int a, int b)
{
    int max_val;
    int temp1;
    int temp2;
    int temp3;
    int temp4;

    temp1 = a + b;
    temp2 = 2 * a - 1;
    temp3 = 2 * b - 1;

    //@ assert temp1 == a + b;
    //@ assert temp2 == 2 * a - 1;
    //@ assert temp3 == 2 * b - 1;

    if (temp1 > temp2)
    {
        if (temp1 > temp3)
        {
            max_val = temp1;
        }
        else
        {
            max_val = temp3;
        }
    }
    else
    {
        if (temp2 > temp3)
        {
            max_val = temp2;
        }
        else
        {
            max_val = temp3;
        }
    }

    //@ assert max_val >= 0;
    //@ assert max_val <= 40;
    //@ assert max_val == a + b || max_val == 2 * a - 1 || max_val == 2 * b - 1;

    return max_val;
}
