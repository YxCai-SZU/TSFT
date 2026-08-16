#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) < 10 ? (r) + 100 * (10 - (n)) : (r));
    ensures n < 10 ==> \result == r + 100 * (10 - n);
    ensures n >= 10 ==> \result == r;
*/
int func(int n, int r)
{
    int res;
    
    if (n < 10)
    {
        //@ assert 10 - n >= 0;
        //@ assert 10 - n <= 9;
        //@ assert r + 100 * (10 - n) >= 0;
        //@ assert r + 100 * (10 - n) <= 4111 + 100 * 9;
        res = r + 100 * (10 - n);
    }
    else
    {
        //@ assert n >= 10;
        res = r;
    }
    
    return res;
}
