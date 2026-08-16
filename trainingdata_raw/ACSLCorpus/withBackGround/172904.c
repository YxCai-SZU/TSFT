#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000000000;
    
    logic integer max_of_four(integer a, integer b, integer c, integer d) =
        (a >= b && a >= c && a >= d) ? a :
        (b >= c && b >= d) ? b :
        (c >= d) ? c : d;
*/

/*@
    requires valid_range(x);
    ensures \result >= 0 && \result <= x;
    assigns \nothing;
*/
int func(int x)
{
    int max_val = 0;
    int i = 1;
    
    //@ assert valid_range(x);
    
    /*@
        loop invariant 1 <= i <= x+1;
        loop invariant max_val >= 0 && max_val <= x;
        loop invariant valid_range(x);
        loop assigns i, max_val;
        loop variant x - i + 1;
    */
    while (i < x)
    {
        int j = i;
        
        /*@
            loop invariant i <= j <= x+1;
            loop invariant max_val >= 0 && max_val <= x;
            loop invariant valid_range(x);
            loop assigns j, max_val;
            loop variant x - j + 1;
        */
        while (j < x)
        {
            int k = j;
            
            /*@
                loop invariant j <= k <= x+1;
                loop invariant max_val >= 0 && max_val <= x;
                loop invariant valid_range(x);
                loop assigns k, max_val;
                loop variant x - k + 1;
            */
            while (k < x)
            {
                int a = i;
                int b = j - i;
                int c = k - j;
                int d = x - k;
                int max = a;
                
                //@ assert a >= 1 && a <= x;
                //@ assert b >= 0 && b <= x;
                //@ assert c >= 0 && c <= x;
                //@ assert d >= 1 && d <= x;
                
                if (b > max) {
                    max = b;
                }
                //@ assert max >= a && max >= b;
                
                if (c > max) {
                    max = c;
                }
                //@ assert max >= a && max >= b && max >= c;
                
                if (d > max) {
                    max = d;
                }
                //@ assert max >= a && max >= b && max >= c && max >= d;
                
                if (max_val < max) {
                    max_val = max;
                }
                //@ assert max_val >= 0 && max_val <= x;
                
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
    
    //@ assert max_val >= 0 && max_val <= x;
    return max_val;
}
