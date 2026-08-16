#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer compute_result(integer n) =
        n % 1000 == 0 ? 0 : 1000 - n % 1000;

    lemma result_less_than_1000:
        \forall integer n; is_valid_n(n) ==> compute_result(n) < 1000;

    lemma result_correct_form:
        \forall integer n; is_valid_n(n) ==> 
            compute_result(n) == 1000 - n % 1000 || compute_result(n) == 0;
*/

/*@
    requires is_valid_n(n);
    ensures \result < 1000;
    ensures \result == 1000 - n % 1000 || \result == 0;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    
    if (n % 1000 == 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = 1000 - n % 1000;
        //@ assert result == 1000 - n % 1000;
    }
    
    //@ assert result < 1000;
    //@ assert result == 1000 - n % 1000 || result == 0;
    
    return result;
}
