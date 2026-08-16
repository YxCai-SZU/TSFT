#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate is_in_range(integer x) = x > 0 && x < 0x10000;
*/

/*@
    logic integer bitwise_and(integer a, integer b) = a & b;
*/

/*@
    lemma commutativity:
        \forall integer a, b;
        is_in_range(a) && is_in_range(b) ==> 
        bitwise_and(a, b) == bitwise_and(b, a);
*/

/*@
    requires is_in_range(a);
    requires is_in_range(b);
    ensures \result == (bitwise_and(a, b) == bitwise_and(b, a));
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert is_positive(a);
    //@ assert is_positive(b);
    //@ assert a < 0x10000;
    //@ assert b < 0x10000;
    
    //@ assert bitwise_and(a, b) == bitwise_and(b, a);
    
    result = true;
    return result;
}
