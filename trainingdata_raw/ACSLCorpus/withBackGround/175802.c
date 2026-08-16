#include <stdint.h>

/*@
    predicate is_positive(integer x) = x > 0;
    
    lemma func_lemma: \forall integer x; is_positive(x) ==> x - 1 >= 0;
*/

/*@
    requires is_positive(x);
    ensures \result == x - 1;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert is_positive(x);
    return x - 1;
}

int main()
{
    uint32_t x;
    uint32_t result;
    
    x = 10;
    //@ assert is_positive(x);
    result = func(x);
    //@ assert result == x - 1;
    
    return 0;
}
