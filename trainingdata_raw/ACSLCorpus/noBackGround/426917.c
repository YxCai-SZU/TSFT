#include <limits.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures ((1 <= (n) <= 9) && (1 <= (m) <= 9)) ==> \result == n * m;
    ensures (!(1 <= (n) <= 9) || !(1 <= (m) <= 9)) ==> \result == -1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_val;
    int product;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    //@ assert n * m <= 400;
    
    max_val = (n > m) ? n : m;
    product = n * m;
    
    if (max_val <= 9)
    {
        return product;
    }
    else
    {
        return -1;
    }
}
