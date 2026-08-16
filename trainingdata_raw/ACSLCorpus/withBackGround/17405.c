#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100;
    
    logic integer func_spec(integer n) = 3 * n * n;
    
    lemma arithmetic_bounds:
        \forall integer n; valid_range(n) ==> 3 * n * n <= 30000;
*/

/*@
    requires valid_range(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    // Variable declarations at top of scope
    int32_t x;
    
    //@ assert valid_range(n);
    //@ assert 3 * n <= 300;
    
    x = 3 * n * n;
    
    //@ assert x == func_spec(n);
    return x;
}

int main(void)
{
    return 0;
}
