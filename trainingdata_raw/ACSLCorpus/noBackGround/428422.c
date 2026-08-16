#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result <= m;
    ensures (m < n ==> \result == m);
    ensures (m >= n ==> \result == n);
    assigns \nothing;
 */
int func(int n, int m)
{
    int result;
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    
    if (m < n)
    {
        //@ assert m < n;
        result = m;
    }
    else
    {
        //@ assert m >= n;
        result = n;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n;
    //@ assert result <= m;
    //@ assert (m < n ==> result == m);
    //@ assert (m >= n ==> result == n);
    
    return result;
}
