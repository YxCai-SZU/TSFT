#include <stdint.h>

/*@
    predicate valid_inputs(integer h, integer a) =
        1 <= h <= 10000 && 1 <= a <= 10000;

    logic integer func_spec(integer h, integer a) =
        h / a + (h % a > 0 ? 1 : 0);

    lemma func_lemma:
        \forall integer h, a;
        valid_inputs(h, a) ==>
        h / a <= func_spec(h, a) <= h / a + 1;
*/


uint32_t func(uint32_t h, uint32_t a)
{
    uint32_t res;
    uint32_t tmp;

    //@ assert valid_inputs(h, a);
    
    tmp = h / a;
    if (h % a > 0)
    {
        res = tmp + 1;
        //@ assert res == h / a + 1;
    }
    else
    {
        res = tmp;
        //@ assert res == h / a;
    }
    
    //@ assert res <= h / a + 1;
    //@ assert res >= h / a;
    
    return res;
}
