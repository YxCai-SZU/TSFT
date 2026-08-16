#include <stddef.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 1000000;
    
    logic integer compute_result(integer n) = (n - 1) / 2 + 1;
    
    lemma result_bounds: \forall integer n; valid_range(n) ==> compute_result(n) <= 1000000;
*/

/*@
    requires valid_range(n);
    ensures \result == compute_result(n);
    ensures \result <= 1000000;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    
    //@ assert 1 <= n <= 1000000;
    //@ assert (n - 1) / 2 + 1 <= 1000000;
    
    result = (n - 1) / 2 + 1;
    
    //@ assert result == compute_result(n);
    //@ assert result <= 1000000;
    
    return result;
}

int main(void)
{
    return 0;
}
