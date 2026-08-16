#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= 100);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int abs_n;
    int abs_k;
    int r;
    int result;

    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (k) && (k) <= 100);
    
    abs_n = n < 0 ? -n : n;
    abs_k = k < 0 ? -k : k;
    
    //@ assert abs_n > 0;
    //@ assert abs_k >= 0;
    
    r = abs_k;
    
    /*@
        loop invariant 0 <= r <= abs_k;
        loop assigns r;
        loop variant r;
    */
    while (r >= abs_n)
    {
        r -= abs_n;
    }
    
    //@ assert 0 <= r < abs_n;
    
    if (r == 0)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
