#include <stdint.h>

/*@
    requires (0 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at scope top
    int32_t res;
    
    //@ assert 0 <= r && r <= 100;
    //@ assert r <= 100;
    //@ assert 0 <= 3 * r;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    res = 3 * r * r;
    return res;
}

int main()
{
    return 0;
}
