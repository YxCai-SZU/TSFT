#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result >= 0 && \result <= 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int abs_n;
    int abs_k;
    int result;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (k) <= 100);
    
    abs_n = n < 0 ? -n : n;
    abs_k = k < 0 ? -k : k;
    
    //@ assert abs_n >= 0 && abs_k > 0;
    //@ assert abs_n <= n;
    
    /*@
        loop invariant 1 <= n <= 100 && 1 <= k <= 100;
        loop invariant abs_n >= 0 && abs_k > 0;
        loop invariant abs_n <= n;
        loop assigns abs_n;
        loop variant abs_n;
    */
    while (abs_n >= abs_k)
    {
        //@ assert abs_n >= abs_k;
        abs_n -= abs_k;
        //@ assert abs_n >= 0;
    }
    
    //@ assert abs_n >= 0 && abs_n < abs_k;
    
    if (abs_n == 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = 1;
        //@ assert result == 1;
    }
    
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    int r1 = func(3, 2);
    //@ assert r1 == 1;
    assert(r1 == 1);
    
    int r2 = func(4, 2);
    //@ assert r2 == 0;
    assert(r2 == 0);
    
    int r3 = func(7, 3);
    //@ assert r3 == 1;
    assert(r3 == 1);
    
    return 0;
}
#endif
