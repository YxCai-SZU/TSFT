#include <stdbool.h>

/*@
    predicate in_range(integer a) = 1 <= a <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        in_range(a) && in_range(b) ==> 1 <= product(a, b) <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    unsigned long long product;
    bool result;
    
    //@ assert a <= 10000 && b <= 10000;
    
    // Proof of product bound
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert a * b <= 10000 * 10000;
    
    product = (unsigned long long)a * (unsigned long long)b;
    result = (product % 2 == 0);
    
    return result;
}
