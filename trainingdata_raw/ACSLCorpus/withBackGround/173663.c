#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    lemma product_range: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> 1 <= a * b <= 9;
    lemma double_product_range: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> 2 <= a * b * 2 <= 18;
    lemma double_a_range: \forall integer a; a_in_range(a) ==> 2 <= a * 2 <= 6;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b * 2 != a * 2 || b == 0);
*/
bool func(int a, int b)
{
    // Variable declarations at top
    bool result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert 1 <= a * b <= 9;
    //@ assert 2 <= a * b * 2 <= 18;
    //@ assert 2 <= a * 2 <= 6;
    
    result = (a * b * 2 != a * 2 || b == 0);
    return result;
}
