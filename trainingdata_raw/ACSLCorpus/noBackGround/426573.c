#include <stdbool.h>

/*@
    requires 1 <= n && n <= 1000000;
    requires 1 <= m && m <= 10000;
    requires 1 <= a && a < b && b <= 10000;
    ensures \result == (b - a < m);
    assigns \nothing;
*/
bool func(int n, int m, int a, int b)
{
    int diff;
    
    //@ assert b > a;
    diff = b - a;
    
    //@ assert diff >= 0;
    //@ assert diff <= 10000;
    
    //@ assert ((diff) >= 0 && (diff) <= 10000 && 1 <= (m) && (m) <= 10000);
    return diff < m;
}
