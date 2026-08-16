#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer func_spec(integer n) = (n * 800) - ((n / 15) * 200);

    lemma func_lemma: \forall integer n; valid_n(n) ==> func_spec(n) >= 0;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert valid_n(n);
    uint32_t result;
    
    result = (n * 800) - ((n / 15) * 200);
    
    //@ assert result == func_spec(n);
    return result;
}

int main()
{
    return 0;
}
