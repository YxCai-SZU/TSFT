#include <stdbool.h>

/*@
    predicate valid_vec(int *a, integer len) =
        len >= 3 &&
        1 <= a[0] <= 100 &&
        1 <= a[1] <= 20 &&
        1 <= a[2] <= 2000;

    logic integer safe_product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
        1 <= x <= 20 && 1 <= y <= 100 ==> safe_product(x, y) <= 2000;
*/

/*@
    requires \valid(a+(0..2));
    requires valid_vec(a, 3);
    ensures \result >= 0;
    ensures \result == a[2] || \result == safe_product(a[1], a[0]);
*/
int func(int *a)
{
    int s;
    int result;
    
    //@ assert 1 <= a[1] && a[1] <= 20;
    //@ assert 1 <= a[0] && a[0] <= 100;
    //@ assert safe_product(a[1], a[0]) <= 2000;
    
    s = a[1] * a[0];
    
    if (s < a[2])
    {
        result = s;
        //@ assert result == safe_product(a[1], a[0]);
    }
    else
    {
        result = a[2];
        //@ assert result == a[2];
    }
    
    return result;
}
