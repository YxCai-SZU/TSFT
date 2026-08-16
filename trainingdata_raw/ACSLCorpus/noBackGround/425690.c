#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int ans;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 2 * 3 == 6;
    //@ assert r * 2 <= 200;
    //@ assert r * 2 * 3 <= 600;
    
    ans = r * 2 * pi;
    return ans;
}
