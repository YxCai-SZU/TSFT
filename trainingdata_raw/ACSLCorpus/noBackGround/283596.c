#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures 0 <= \result && \result < 1000;
    ensures \result == ((((n)) % 1000) == 0 ? 0 : 1000 - (((n)) % 1000));
    assigns \nothing;
*/
int func(int n)
{
    int m;
    int a;
    
    m = n;
    a = 1000;
    
    /*@
        loop invariant 0 <= m && m <= n;
        loop invariant a == 1000;
        loop invariant n - m == ((n - m) / 1000) * 1000;
        loop assigns m;
        loop variant m;
    */
    while (m >= a)
    {
        //@ assert m >= 1000;
        m = m - a;
    }
    
    //@ assert 0 <= m && m < 1000;
    
    if (m == 0)
    {
        //@ assert ((n) % 1000) == 0;
        //@ assert ((((n)) % 1000) == 0 ? 0 : 1000 - (((n)) % 1000)) == 0;
        return 0;
    }
    else
    {
        //@ assert ((n) % 1000) == m;
        //@ assert ((((n)) % 1000) == 0 ? 0 : 1000 - (((n)) % 1000)) == 1000 - m;
        return 1000 - m;
    }
}
