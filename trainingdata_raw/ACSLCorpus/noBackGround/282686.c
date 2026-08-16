#include <stdint.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    // Variable declarations at scope top
    int32_t b;
    
    //@ assert 0 <= r <= 4500;
    //@ assert 0 <= g <= 4500;
    //@ assert 2 * g <= 9000;
    //@ assert 2 * g >= 0;
    //@ assert 2 * g - r >= -4500;
    //@ assert 2 * g - r <= 9000;
    
    b = 2 * g - r;
    //@ assert b == (2 * (g) - (r));
    return b;
}

int main(void)
{
    return 0;
}
