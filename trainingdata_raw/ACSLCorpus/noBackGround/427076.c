#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    requires r == (int)r;
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t ans;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 3 * r * r <= 3 * 100 * 100;
    //@ assert 3 * r * r >= 3 * 1 * 1;
    
    ans = 3 * r * r;
    return ans;
}

int main()
{
    return 0;
}
