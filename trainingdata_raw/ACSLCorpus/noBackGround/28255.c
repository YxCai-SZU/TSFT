#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    //@ assert (1 <= (r) <= 100);
    
    //@ assert 3 * 1 * 1 <= 3 * r * r;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    return 3 * r * r;
}

int main()
{
    return 0;
}
