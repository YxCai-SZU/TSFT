#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer scaled_pi(integer n) = 2 * 3141592653 * n;
    
    logic integer compute_result(integer n) = scaled_pi(n) / 1000000000;
*/


int64_t func(int64_t n)
{
    int64_t pi = 3141592653;
    int64_t scale_factor = 1000000000;
    int64_t result = 0;
    int64_t temp = 2 * pi * n;
    
    
    while (temp >= scale_factor)
    {
        temp -= scale_factor;
        result += 1;
    }
    
    //@ assert result * scale_factor + temp == scaled_pi(n);
    
    return result;
}

/*@
    lemma result_correctness:
        \forall integer n; valid_n(n) ==> compute_result(n) == scaled_pi(n) / 1000000000;
*/

int main()
{
    return 0;
}
