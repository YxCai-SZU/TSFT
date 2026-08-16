#include <stdbool.h>

/*@
    predicate in_range(integer x) = 0 <= x && x <= 10000;
    
    logic integer mod2(integer x) = x % 2;
    
    lemma product_bound: \forall integer a, b; in_range(a) && in_range(b) ==> a * b <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == (a * b % 2 != 0);
*/
bool func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    bool is_odd = false;
    unsigned int product = a * b;
    
    //@ assert a * b <= 100000000;
    
    /*@
        loop invariant 0 <= a && a <= 10000;
        loop invariant 0 <= b && b <= 10000;
        loop invariant product <= a * b;
        loop invariant product >= 0;
        loop invariant product % 2 == a * b % 2;
        loop assigns product;
        loop variant product;
    */
    while (product >= 2) {
        product -= 2;
    }
    
    if (product == 1) {
        is_odd = true;
    }
    
    return is_odd;
}
