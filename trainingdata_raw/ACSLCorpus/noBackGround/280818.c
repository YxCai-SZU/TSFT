#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (((n) - 1) / 2 + 1);
    ensures \result > 0;
    ensures \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    
    //@ assert n > 0;
    //@ assert n <= 100;
    //@ assert (n - 1) / 2 <= 49;
    //@ assert (n - 1) / 2 + 1 <= 50;
    
    result = (n - 1) / 2 + 1;
    
    //@ assert result == (n - 1) / 2 + 1;
    //@ assert result > 0;
    //@ assert result <= n;
    
    return result;
}

int main()
{
    return 0;
}
