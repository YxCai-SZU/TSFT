#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer square_plus_one(integer a) = (a + 1) * (a + 1);
    
    lemma square_bound: \forall integer a; a_in_range(a) ==> square_plus_one(a) <= 10201;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (square_plus_one(a) <= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    bool result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    //@ assert a + 1 <= 101;
    //@ assert square_plus_one(a) <= 10201;
    
    result = (a + 1) * (a + 1) <= b;
    
    //@ assert result == (square_plus_one(a) <= b);
    return result;
}
