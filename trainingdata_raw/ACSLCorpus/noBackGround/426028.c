#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n)) - a;
    ensures \result >= 0;
*/
int32_t func(int32_t n, int32_t a)
{
    // Variable declarations at top of scope
    int32_t b;
    
    //@ assert 0 <= ((n) * (n));
    //@ assert ((n) * (n)) <= 10000;
    //@ assert ((n) * (n)) - a >= 0;
    
    b = n * n - a;
    return b;
}

int main(void)
{
    return 0;
}
