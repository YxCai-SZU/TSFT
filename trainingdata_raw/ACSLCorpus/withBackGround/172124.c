#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer calculate_res(integer a, integer b) =
        a + b == 3 ? 6 - (a + b) :
        a + b == 5 ? 1 : 2;

    lemma res_properties:
        \forall integer a, b;
        valid_range(a, b) ==>
            calculate_res(a, b) + a + b == 6 &&
            (calculate_res(a, b) == 1 || calculate_res(a, b) == 2 || calculate_res(a, b) == 3);
*/

/*@
    requires valid_range(a, b);
    ensures \result + a + b == 6;
    ensures \result == 1 || \result == 2 || \result == 3;
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;

    //@ assert valid_range(a, b);
    
    if (a + b == 3)
    {
        res = 6 - (a + b);
        //@ assert res + a + b == 6;
    }
    else if (a + b == 5)
    {
        res = 1;
        //@ assert res + a + b == 6;
    }
    else
    {
        res = 2;
        //@ assert res + a + b == 6;
    }

    //@ assert res == 1 || res == 2 || res == 3;
    return res;
}
