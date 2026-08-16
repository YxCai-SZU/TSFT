#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_range: 
        \forall integer x, y; 
        valid_range(x) && valid_range(y) ==> 
        1 <= product(x, y) <= 100;
*/

/*@
    requires valid_range(x) && valid_range(y) && valid_range(z);
    ensures \result == product(x, y) + z;
    assigns \nothing;
*/
int check_non_linear_arith(int x, int y, int z) {
    // Variable declarations at scope top
    int product;
    int result;
    
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert valid_range(z);
    
    //@ assert 1 <= product(x, y) <= 100;
    product = x * y;
    
    result = product + z;
    //@ assert result == product(x, y) + z;
    
    return result;
}
