#include <stdbool.h>
/*@
    predicate valid_range(integer n) = 1 <= n <= 100000;
    predicate loop_inv(integer i, integer n, integer max, integer result) =
        1 <= i <= n &&
        1 <= max <= n &&
        1 <= result <= n &&
        valid_range(n);
*/

/*@
    requires valid_range(n);
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int func(int n)
{
    int max = 1;
    int i = 1;
    int result = 1;
    
    /*@
        loop invariant loop_inv(i, n, max, result);
        loop assigns i, max, result;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 1 <= i < n;
        
        if (max <= n - i)
        {
            result = max + 1;
        }
        else
        {
            result = n - i + 1;
        }
        
        //@ assert 1 <= result <= n;
        
        if (max < result)
        {
            max = result;
        }
        
        //@ assert 1 <= max <= n;
        
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert 1 <= result <= n;
    
    return result;
}
