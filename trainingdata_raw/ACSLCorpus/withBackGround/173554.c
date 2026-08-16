#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= a <= 100 &&
        1 <= b <= 20 &&
        1 <= c <= 2000;

    logic integer compute_result(integer a, integer b, integer c) =
        (b * a > c) ? c : b * a;

    lemma product_bound: \forall integer a, b;
        valid_params(a, b, 2000) ==> b * a <= 2000;
*/

/*@
    requires valid_params(a, b, c);
    ensures \result <= c;
    ensures \result >= 0;
    ensures (b * a > c ==> \result == c) && (b * a <= c ==> \result == b * a);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert valid_params(a, b, c);
    
    int product;
    int result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 20;
    //@ assert b * a <= 2000;
    
    product = b * a;
    
    if (product > c)
    {
        result = c;
    }
    else
    {
        result = product;
    }
    
    //@ assert result <= c;
    //@ assert result >= 0;
    //@ assert (b * a > c ==> result == c) && (b * a <= c ==> result == b * a);
    
    return result;
}
