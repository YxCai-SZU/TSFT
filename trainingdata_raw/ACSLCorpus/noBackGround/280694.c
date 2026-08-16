#include <stdint.h>

/*@
    requires ((1 <= ((a)) <= 5) && (1 <= ((b)) <= 5));
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) <= 5);
    //@ assert (1 <= (b) <= 5);
    //@ assert ((a) * (b)) <= 25;
    return a * b;
}

int main()
{
    return 0;
}
