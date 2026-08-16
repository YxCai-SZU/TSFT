#include <stdbool.h>

/*@
    predicate is_odd(integer x) = (x % 2) != 0;
    logic integer product(integer a, integer b) = a * b;
    lemma product_range: \forall integer a, b; 1 <= a <= 3 && 1 <= b <= 3 ==> 0 <= product(a, b) <= 9;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool res;

    //@ assert a >= 1 && a <= 3;
    //@ assert b >= 1 && b <= 3;
    
    product = a * b;
    //@ assert 0 <= product <= 9;
    
    res = (product % 2) != 0;
    //@ assert res == ((product % 2) != 0);
    
    return res;
}
