#include <stdint.h>

/*@
    predicate is_valid_s(integer s) = 1 <= s <= 100;
    logic integer square(integer s) = s * s;
    lemma square_bounds: \forall integer s; is_valid_s(s) ==> 1 <= square(s) <= 10000;
*/

/*@
    requires is_valid_s(s);
    ensures \result == square(s);
    assigns \nothing;
*/
int32_t func(int32_t s)
{
    // Variable declarations at top of scope
    int32_t res;
    
    //@ assert is_valid_s(s);
    //@ assert 1 <= square(s) <= 10000;
    
    res = s * s;
    
    //@ assert res == square(s);
    return res;
}

int main(void)
{
    return 0;
}
