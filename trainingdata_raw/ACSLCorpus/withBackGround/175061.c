#include <stdbool.h>
#include <stddef.h>

/*@
    predicate lower_bound(integer k) = 1 <= k <= 200;
    predicate result_range(integer r, integer k) = r >= 1 && r <= k * 2;
    predicate loop_invariant(integer k, integer i, integer r) =
        1 <= k <= 200 &&
        1 <= i <= k &&
        r >= 1 &&
        r <= i * 2 &&
        (i > 1 ==> r <= k * 2);
*/

/*@
    requires lower_bound(k);
    ensures result_range(\result, k);
    assigns \nothing;
*/
int func(size_t k)
{
    int result = 1;
    size_t i = 1;
    
    /*@
        loop invariant loop_invariant(k, i, result);
        loop assigns result, i;
        loop variant k - i;
    */
    while (i < k)
    {
        //@ assert loop_invariant(k, i, result);
        result += 1;
        
        if (k % i == 0)
        {
            result += 1;
        }
        
        i += 1;
        //@ assert loop_invariant(k, i, result);
    }
    
    //@ assert result_range(result, k);
    return result;
}

int main()
{
    return 0;
}
