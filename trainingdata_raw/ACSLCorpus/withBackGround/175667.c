#include <stdbool.h>

/*@
    predicate is_product_less_200(integer x, integer y) =
        x * y < 200;
*/

/*@
    lemma product_bound:
        \forall integer x, y;
            0 <= x <= 100 && 0 <= y <= 100 ==> x * y <= 10000;
*/

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures \result == true <==> x * y < 200;
    assigns \nothing;
*/
bool func(int x, int y)
{
    int product;
    bool result;

    //@ assert 0 <= x && x <= 100;
    //@ assert 0 <= y && y <= 100;
    //@ assert x * y <= 10000;

    product = x * y;

    if (product < 200)
    {
        //@ assert product < 200;
        result = true;
    }
    else
    {
        //@ assert product >= 200;
        result = false;
    }

    return result;
}
