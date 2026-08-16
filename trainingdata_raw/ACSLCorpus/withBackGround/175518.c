#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    logic integer func_spec(integer a, integer b) =
        a > b ? a + b : b - a;

    lemma func_lemma:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        func_spec(a, b) == a + b || func_spec(a, b) == b - a;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a + b || \result == b - a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result = 0;
    //@ assert valid_range(a) && valid_range(b);
    
    if (a > b) {
        result = a + b;
        //@ assert result == a + b;
    } else {
        result = b - a;
        //@ assert result == b - a;
    }
    
    return result;
}

/*@
    logic integer func2_spec(integer a) = a + a;

    lemma func2_lemma:
        \forall integer a;
        valid_range(a) ==> func2_spec(a) == a + a;
*/

/*@
    requires valid_range(a);
    ensures \result == a + a;
    assigns \nothing;
*/
uint32_t func2(uint32_t a)
{
    uint32_t result = 0;
    //@ assert valid_range(a);
    
    result = a + a;
    //@ assert result == a + a;
    
    return result;
}

/*@
    assigns \nothing;
*/
uint32_t read_input(void)
{
    return 0;
}

int main(void)
{
    return 0;
}
