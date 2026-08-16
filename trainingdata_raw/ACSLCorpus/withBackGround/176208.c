#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *p, size_t n) =
        n > 0 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= p[i] <= (int)n &&
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@
    requires valid_array(p, n);
    ensures \result >= 0;
    ensures \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *p)
{
    int result = 0;
    int max = p[0];
    int min = p[0];
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> 1 <= p[k] <= (int)n;
        loop invariant \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
        loop invariant result >= 0;
        loop invariant result <= (int)i;
        loop assigns i, result, max, min;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        
        if (p[i] <= max && p[i] <= min)
        {
            //@ assert result >= 0;
            result += 1;
        }
        
        if (p[i] > max)
        {
            max = p[i];
        }
        
        if (p[i] < min)
        {
            min = p[i];
        }
        
        i += 1;
    }
    
    return result;
}
