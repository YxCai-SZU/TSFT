#include <stdbool.h>

/*@
    predicate total_formula(integer a, integer total) =
        total == a * 2 + (a - 1);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (b >= a && a * 2 + (a - 1) <= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int total;

    total = a * 2 + (a - 1);
    //@ assert total_formula(a, total);

    if (total <= b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
