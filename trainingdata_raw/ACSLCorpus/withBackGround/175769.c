#include <stdint.h>

/*@
    predicate is_valid_u32_range(integer a) =
        1 <= a && a <= 100;
    
    lemma square_bound:
        \forall integer a; is_valid_u32_range(a) ==> a * a <= 10000;
*/

/*@
    requires is_valid_u32_range(a);
    ensures \result == a * a;
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert is_valid_u32_range(a);
    //@ assert a * a <= 10000;
    return a * a;
}

/*@
    predicate is_valid_i32_range(integer x, integer y) =
        1 <= x && x <= 100 &&
        1 <= y && y <= 100 &&
        x <= 46340;
    
    lemma product_bound_i32:
        \forall integer x, y;
            is_valid_i32_range(x, y) ==> x * y <= 46340 * 100;
*/

/*@
    requires is_valid_i32_range(x, y);
    ensures \result == x * y;
    assigns \nothing;
*/
int32_t func2(int32_t x, int32_t y)
{
    //@ assert is_valid_i32_range(x, y);
    //@ assert x * y <= 46340 * 100;
    return x * y;
}

/*@
    predicate is_valid_u32_pair(integer x, integer y) =
        1 <= x && x <= 100 &&
        1 <= y && y <= 100;
    
    lemma product_bound_u32:
        \forall integer x, y;
            is_valid_u32_pair(x, y) ==> x * y <= 100 * 100;
*/

/*@
    requires is_valid_u32_pair(x, y);
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func3(uint32_t x, uint32_t y)
{
    //@ assert is_valid_u32_pair(x, y);
    //@ assert x * y <= 100 * 100;
    return x * y;
}
