#include <stdbool.h>

/*@
    predicate in_range(integer x) = 0 <= x <= 100;
    
    logic integer dot_product(integer a, integer b, integer c, integer d) =
        a * c + b * d;
    
    lemma dot_product_bounds:
        \forall integer a, b, c, d;
            in_range(a) && in_range(b) && in_range(c) && in_range(d) ==>
            0 <= a * c <= 10000 && 0 <= b * d <= 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == true <==> dot_product(a, b, c, d) > 0;
    assigns \nothing;
*/
bool func(long long a, long long b, long long c, long long d)
{
    long long dot_product;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    
    //@ assert 0 <= a * c <= 10000;
    //@ assert 0 <= b * d <= 10000;
    
    dot_product = a * c + b * d;
    
    if (dot_product > 0) {
        //@ assert dot_product(a, b, c, d) > 0;
        return true;
    } else if (dot_product < 0) {
        //@ assert dot_product(a, b, c, d) <= 0;
        return false;
    } else {
        if ((a == 0 && b == 0) || (c == 0 && d == 0)) {
            //@ assert dot_product(a, b, c, d) == 0;
        } else {
            //@ assert dot_product(a, b, c, d) == 0;
        }
    }
    
    //@ assert dot_product(a, b, c, d) <= 0;
    return false;
}
