#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 20 &&
        1 <= c && c <= 2000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer a, b;
        valid_input(a, b, 2000) ==> safe_product(a, b) <= 2000;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result <= c;
    ensures \result == a * b || \result == c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int product;
    int result;

    //@ assert valid_input(a, b, c);
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= c && c <= 2000;
    
    //@ assert a * b <= 100 * 20;
    
    product = a * b;
    
    if (product < c) {
        result = product;
    } else {
        result = c;
    }
    
    //@ assert result <= c;
    //@ assert result == a * b || result == c;
    
    return result;
}
