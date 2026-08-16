#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    predicate product_in_range(integer a, integer b) = a * b <= 9;
    predicate double_product_in_range(integer a, integer b) = a * b * 2 <= 18;
    
    lemma product_range_lemma:
        \forall integer a, b; a_in_range(a) && b_in_range(b) ==> product_in_range(a, b);
    
    lemma double_product_range_lemma:
        \forall integer a, b; a_in_range(a) && b_in_range(b) ==> double_product_in_range(a, b);
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b * 2 != 0);
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a >= 1 && a <= 3;
    //@ assert b >= 1 && b <= 3;
    //@ assert a * b <= 9;
    //@ assert a * b * 2 <= 18;
    
    if (a * b * 2 != 0) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
