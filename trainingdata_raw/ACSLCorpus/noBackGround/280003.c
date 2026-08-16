#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 23);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n >= 20;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert (1 <= (n) && (n) <= 23);
    
    if (n >= 20) {
        result = 1;
        //@ assert result == 1 && n >= 20;
    } else {
        //@ assert n < 20;
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> n >= 20;
    
    return result;
}

int main(void)
{
    return 0;
}
