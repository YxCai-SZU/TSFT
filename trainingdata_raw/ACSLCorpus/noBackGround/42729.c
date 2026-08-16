#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((r) + (((n)) >= 10 ? 0 : 100 * (10 - ((n)))));
    ensures n >= 10 ==> \result == r;
    ensures n < 10 ==> \result == r + 100 * (10 - n);
*/
int func(int n, int r)
{
    int add;
    int res;
    
    //@ assert (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    
    if (n >= 10) {
        add = 0;
    } else {
        add = 100 * (10 - n);
    }
    
    //@ assert add == ((n) >= 10 ? 0 : 100 * (10 - (n)));
    //@ assert 0 <= add <= 100 * 10;
    //@ assert 0 <= r + add <= 4111 + 100 * 10;
    //@ assert r + add >= 0;
    
    res = r + add;
    
    //@ assert res == ((r) + (((n)) >= 10 ? 0 : 100 * (10 - ((n)))));
    return res;
}
