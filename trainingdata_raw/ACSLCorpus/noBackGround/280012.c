#include <stdint.h>

/*@
    requires ((a) <= 10000 && (b) <= 10000 && (uint64_t)(a) * (b) <= 100000000);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t a, uint32_t b)
{
    //@ assert ((a) <= 10000 && (b) <= 10000 && (uint64_t)(a) * (b) <= 100000000);
    //@ assert (uint64_t)a * b <= 100000000;
    
    uint32_t result;
    result = a * b;
    
    //@ assert result == ((a) * (b));
    return result;
}

int main()
{
    return 0;
}
