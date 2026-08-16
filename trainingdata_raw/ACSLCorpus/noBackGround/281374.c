#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (180 * ((n) - 2));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert 3 <= n && n <= 100;
    //@ assert 1 <= n - 2 && n - 2 <= 98;
    //@ assert 180 * (n - 2) == 180 * (n - 2);
    
    result = 180 * ((int32_t)n - 2);
    return result;
}

int main()
{
    return 0;
}
