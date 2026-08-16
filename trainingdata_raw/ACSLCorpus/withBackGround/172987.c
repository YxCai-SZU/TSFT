#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_in_range:
        \forall integer x, y; valid_range(x) && valid_range(y) ==> 
        1 <= product(x, y) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int ab;
    int cd;
    int result;
    
    // Precondition assertions
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    // Multiplication with overflow prevention
    //@ assert product(a, b) <= 100000000;
    ab = a * b;
    
    //@ assert product(c, d) <= 100000000;
    cd = c * d;
    
    // Return maximum value
    if (ab > cd) {
        //@ assert ab >= product(a, b);
        //@ assert ab >= product(c, d);
        result = ab;
    } else {
        //@ assert cd >= product(a, b);
        //@ assert cd >= product(c, d);
        result = cd;
    }
    
    // Postcondition verification
    //@ assert result == product(a, b) || result == product(c, d);
    //@ assert result >= product(a, b);
    //@ assert result >= product(c, d);
    
    return result;
}
