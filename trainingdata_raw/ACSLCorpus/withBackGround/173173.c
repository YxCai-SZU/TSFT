#include <stdbool.h>
#include <stdint.h>

/*@
    predicate in_u32_range(integer x) = 0 <= x <= 0xFFFFFFFF;

    logic integer bitwise_and(integer a, integer b) = a & b;

    lemma and_commutative:
        \forall integer a, b;
            in_u32_range(a) && in_u32_range(b) ==>
            bitwise_and(a, b) == bitwise_and(b, a);

    lemma and_idempotent:
        \forall integer a, b;
            in_u32_range(a) && in_u32_range(b) ==>
            bitwise_and(a, b) == bitwise_and(a, b);
*/

/*@
    requires in_u32_range(a);
    requires in_u32_range(b);
    requires in_u32_range(c);
    ensures \result == ((a & b) == c);
*/
bool func(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert in_u32_range(a);
    //@ assert in_u32_range(b);
    //@ assert in_u32_range(c);
    
    //@ assert bitwise_and(a, b) == bitwise_and(b, a);
    //@ assert bitwise_and(a, b) == bitwise_and(a, b);
    
    bool result = (a & b) == c;
    
    //@ assert result == ((a & b) == c);
    return result;
}
