#include <stdint.h>

/*@
    predicate is_seven(integer x) = x == 7;

    lemma xor_zero_identity:
        \forall integer x; (x ^ 0) == x;
*/

/*@
    requires a == 7;
    ensures \result == 7;
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t result;
    
    //@ assert a == 7;
    //@ assert (a ^ 0) == a;
    //@ assert (a ^ 0) == 7;
    
    result = a ^ 0;
    return result;
}

int main(void)
{
    return 0;
}
