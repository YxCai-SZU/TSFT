#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures ((n) % 1000 == 0) ==> \result == 0;
    ensures ((n) % 1000 != 0) ==> \result == (1000 - ((n) % 1000));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t three_digit;
    uint32_t res;
    
    three_digit = n % 1000;
    
    if (three_digit == 0)
    {
        //@ assert ((n) % 1000 == 0);
        res = 0;
    }
    else
    {
        //@ assert ((n) % 1000 != 0);
        res = 1000 - three_digit;
    }
    
    return res;
}

int main()
{
    return 0;
}
