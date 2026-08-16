#include <stdbool.h>

/*@
    predicate in_range(integer x) = 0 <= x <= 100;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> 0 <= safe_product(a, b) <= 10000;

    lemma product_comparison:
        \forall integer a, b, c, prod;
            in_range(a) && in_range(b) && in_range(c) && prod == safe_product(a, b) ==>
                (prod >= c <==> safe_product(a, b) >= c);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == true <==> a * b >= c;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int product;
    bool result;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;
    
    //@ assert 0 <= a * b && a * b <= 10000;
    
    product = a * b;
    
    //@ assert product >= c <==> a * b >= c;
    
    result = (product >= c);
    return result;
}
