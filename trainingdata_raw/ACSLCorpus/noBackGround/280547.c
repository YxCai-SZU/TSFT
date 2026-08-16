#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 9);
    ensures \result == ((input) * 2);
    assigns \nothing;
*/
int32_t func(uint32_t input)
{
    uint32_t output;
    
    //@ assert (1 <= (input) && (input) <= 9);
    output = input * 2;
    
    //@ assert 2 <= output && output <= 18;
    return (int32_t)output;
}

int main(void)
{
    return 0;
}
