#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 1000000;
    predicate loop1_inv(integer n, integer i, integer result) =
        valid_range(n) &&
        1 <= i <= n + 1 &&
        result >= 0 &&
        result <= i - 1;
    predicate loop2_inv(integer n, integer i, integer j, integer result) =
        valid_range(n) &&
        1 <= i <= n + 1 &&
        1 <= j <= n + 1 &&
        result >= 0 &&
        result <= i - 1;
*/

/*@
    requires 1 <= n <= 1000000;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result = 0;
    int64_t i = 1;
    
    /*@
        loop invariant loop1_inv(n, i, result);
        loop assigns i, result;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        int64_t j = 1;
        
        /*@
            loop invariant loop2_inv(n, i, j, result);
            loop assigns j, result;
            loop variant n - j + 1;
        */
        while (j <= n)
        {
            //@ assert i * 8 <= n * 8;
            
            uint64_t n_unsigned = (n < 0) ? 0 : (uint64_t)n;
            uint64_t i_unsigned = (uint64_t)i;
            uint64_t j_unsigned = (uint64_t)j;
            
            if ((i_unsigned * 8) / 100 == j_unsigned && 
                (j_unsigned * 10) / 100 == n_unsigned)
            {
                result += 1;
                break;
            }
            j += 1;
        }
        i += 1;
    }
    return result;
}

/*@
    lemma bounds_preserved: \forall integer n, i, j; 
        valid_range(n) && 1 <= i <= n && 1 <= j <= n ==> 
        i * 8 <= n * 8 && i * 10 <= n * 10;
*/

int main()
{
    return 0;
}
