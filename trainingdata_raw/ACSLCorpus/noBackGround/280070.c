#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert r >= 1;
    //@ assert r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    res = 3 * r * r;
    return res;
}

int main(void)
{
    return 0;
}
