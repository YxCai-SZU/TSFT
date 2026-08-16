#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer compute_result(integer n) = (n + 1) / 2;
    
    lemma result_bounds: 
        \forall integer n; is_valid_n(n) ==> 
            compute_result(n) >= 1 && compute_result(n) <= 50;
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_result(n);
    ensures \result >= 1;
    ensures \result <= 50;
    assigns \nothing;
*/
size_t func(size_t n)
{
    // Variable declarations at top of scope
    size_t result;
    
    //@ assert is_valid_n(n);
    
    result = (n + 1) / 2;
    
    //@ assert result == compute_result(n);
    //@ assert result >= 1;
    //@ assert result <= 50;
    
    return result;
}

int main()
{
    return 0;
}
