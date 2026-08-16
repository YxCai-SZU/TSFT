#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result >= 0;
    ensures \result == ((n) > (m) * 2 ? (n) - (m) * 2 : 0);
    assigns \nothing;
*/
int func(int n, int m)
{
    int res;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n > m * 2)
    {
        //@ assert n > m * 2;
        //@ assert n - m * 2 >= 0;
        res = n - m * 2;
    }
    else
    {
        res = 0;
    }
    
    //@ assert res == ((n) > (m) * 2 ? (n) - (m) * 2 : 0);
    return res;
}
