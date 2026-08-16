#include <stdint.h>

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t multiply(uint32_t x, uint32_t y)
{
    //@ assert (0 <= (x) && (x) <= 100 && 0 <= (y) && (y) <= 100);
    //@ assert x * y <= 10000;
    return x * y;
}

int main()
{
    uint32_t m;
    m = multiply(10, 20);
    return 0;
}
