#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 1000;
    
    logic integer func_spec(integer n) = n / 3;
    
    lemma func_lemma:
        \forall integer n;
        valid_n(n) ==>
        func_spec(n) >= 0 &&
        func_spec(n) * 3 <= n &&
        n - func_spec(n) * 3 < 3;
*/

/*@
    requires valid_n(n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result * 3 <= n;
    ensures n - \result * 3 < 3;
*/
uint64_t func(uint64_t n)
{
    uint64_t ans;
    
    ans = n / 3;
    
    //@ assert ans >= 0;
    //@ assert ans * 3 <= n;
    //@ assert n - ans * 3 < 3;
    
    return ans;
}

int main()
{
    return 0;
}
