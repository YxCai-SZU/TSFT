#include <stdint.h>

/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) + (((x)) * ((x))) + (((x)) * ((x)) * ((x))));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert (1 <= (x) <= 10);
    //@ assert ((x) * (x)) <= 100;
    //@ assert ((x) * (x) * (x)) <= 1000;
    //@ assert x <= 10;
    
    result = x + (x * x) + (x * x * x);
    
    //@ assert result == ((x) + (((x)) * ((x))) + (((x)) * ((x)) * ((x))));
    return result;
}

int main(void)
{
    return 0;
}
