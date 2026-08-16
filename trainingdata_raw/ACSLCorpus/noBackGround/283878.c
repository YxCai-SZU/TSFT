#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures -3 <= \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int max_sum = 0;
    int n = 0;

    /*@
        loop invariant 0 <= n <= k;
        loop invariant -n <= max_sum <= n;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
        loop assigns n, max_sum;
        loop variant k - n;
    */
    while (n < k)
    {
        //@ assert -n <= max_sum <= n;
        
        if (n < a)
        {
            max_sum += 1;
        }
        else if (n < a + b)
        {
            max_sum += 0;
        }
        else
        {
            max_sum += -1;
        }
        
        n += 1;
        
        //@ assert -n <= max_sum <= n;
    }
    
    //@ assert -3 <= max_sum <= 3;
    return max_sum;
}
