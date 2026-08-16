#include <stdint.h>

/*@
    requires n <= 0x1000;
    ensures \result == (((n) * ((n) + 1)) / 2);
    ensures \result <= (0x1000 * (0x1000 + 1)) / 2;
    assigns \nothing;
*/
uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t intermediate_product;
    uint32_t result;

    //@ assert n <= 0x1000;
    
    //@ assert n * (n + 1) <= 0x1000 * (0x1000 + 1);
    intermediate_product = n * (n + 1);
    
    result = intermediate_product / 2;
    
    //@ assert result == (n * (n + 1)) / 2;
    //@ assert result <= (0x1000 * (0x1000 + 1)) / 2;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
