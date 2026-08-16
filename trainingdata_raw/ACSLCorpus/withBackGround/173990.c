#include <stdbool.h>
#include <stdint.h>

/*@
    predicate no_overflow_plus(uint32_t a, uint32_t b) =
        a <= 0x7fffffff && b <= 0x7fffffff;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_no_overflow:
        \forall integer a, b;
            a <= 0x7fffffff && b <= 0x7fffffff ==> a + b <= 0xffffffff;
*/

/*@
    requires no_overflow_plus(a, b);
    ensures \result == sum(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert no_overflow_plus(a, b);
    //@ assert a + b <= 0xffffffff;
    return a + b;
}

/*@
    ensures \result == true;
    assigns \nothing;
*/
bool func2(void)
{
    //@ assert 1 <= 1;
    return true;
}
