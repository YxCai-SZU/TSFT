#include <stdint.h>

/*@
    requires (1 <= (n) <= 10);
    ensures \result == ((n) + (n) * (n) + (n) * (n) * (n));
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    //@ assert (1 <= (n) <= 10);
    
    //@ assert ((n) + (n) * (n) + (n) * (n) * (n)) <= 10 + 10 * 10 + 10 * 10 * 10;
    
    return n + n * n + n * n * n;
}

int main()
{
    return 0;
}
