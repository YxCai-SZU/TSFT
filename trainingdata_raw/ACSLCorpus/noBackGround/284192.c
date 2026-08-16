#include <stdint.h>

/*@
    requires ((n) > 1 &&
        (n) <= 0xFFFFFFFF / (n));
    ensures ((\result) == (n) * (n) &&
        (\result) >= 1 &&
        (\result) <= 0xFFFFFFFF);
    assigns \nothing;
*/
uint32_t is_square(uint32_t n)
{
    //@ assert n > 1;
    //@ assert n <= 0xFFFFFFFF / n;
    //@ assert n * n <= 0xFFFFFFFF;
    //@ assert n * n >= 1;
    
    return n * n;
}

int main(void)
{
    return 0;
}
