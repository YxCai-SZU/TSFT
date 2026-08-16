#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t res;

    //@ assert (1 <= (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    
    res = r * r;
    return res;
}

int main(void)
{
    return 0;
}
