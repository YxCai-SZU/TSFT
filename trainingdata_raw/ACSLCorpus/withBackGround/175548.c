#include <stdbool.h>

/*@
    predicate in_range(integer a) = 1 <= a <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        in_range(a) && in_range(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires in_range(a);
    requires in_range(b);
    ensures \result == (product(a, b) % 2 != 0);
*/
bool func(unsigned long a, unsigned long b) {
    // Variable declarations at scope top
    unsigned long product_val;
    bool result;
    
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    
    // Proof of product bound
    //@ assert product(a, b) <= 100000000;
    
    product_val = a * b;
    result = (product_val % 2) != 0;
    
    return result;
}
