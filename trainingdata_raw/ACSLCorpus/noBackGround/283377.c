#include <stdbool.h>
#include <limits.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (x % 100) * 21 <= x;
    ensures \result == 0 ==> (x % 100) * 21 > x;
*/
int func(unsigned int x)
{
    unsigned int d2;
    unsigned int n;
    int res;
    
    //@ assert (1 <= (x) <= 100000);
    d2 = x % 100;
    //@ assert d2 == ((x) % 100);
    n = d2 * 21;
    //@ assert n == ((((x) % 100)) * 21);
    
    if (n > x) {
        //@ assert ((((x) % 100)) * 21) > x;
        //@ assert (x % 100) * 21 > x;
        res = 0;
    } else {
        //@ assert ((((x) % 100)) * 21) <= x;
        //@ assert (x % 100) * 21 <= x;
        res = 1;
    }
    
    //@ assert res == 0 || res == 1;
    //@ assert res == 1 ==> (x % 100) * 21 <= x;
    //@ assert res == 0 ==> (x % 100) * 21 > x;
    return res;
}
