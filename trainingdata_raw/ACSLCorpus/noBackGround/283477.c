#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 3 * (int64_t)r * (int64_t)r >= 0;
    //@ assert 3 * (int64_t)r * (int64_t)r <= INT32_MAX;
    
    return 3 * r * r;
}

int main()
{
    return 0;
}
