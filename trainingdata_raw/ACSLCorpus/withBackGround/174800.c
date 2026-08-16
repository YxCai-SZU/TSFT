#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer half(integer n) = n / 2;
    logic integer remainder(integer n) = n % 2;
    logic integer expected_result(integer n) = half(n) + remainder(n);

    lemma result_correctness:
        \forall integer n;
            is_valid_n(n) ==>
            half(n) + remainder(n) == expected_result(n);
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result = 0;
    size_t half_n = n / 2;
    result += half_n;
    
    if (n % 2 == 1)
    {
        result += 1;
    }
    
    //@ assert result == half_n + (n % 2);
    //@ assert result == expected_result(n);
    
    return result;
}
