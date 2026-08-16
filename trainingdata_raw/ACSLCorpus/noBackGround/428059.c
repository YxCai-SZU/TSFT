#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 2896);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t my_triangular_number(uint32_t n)
{
    //@ assert (0 <= (n) && (n) <= 2896);
    
    //@ assert n * (n + 1) <= 2896 * (2896 + 1);
    //@ assert n * (n + 1) / 2 <= 2896 * (2896 + 1) / 2;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    
    return n * (n + 1) / 2;
}

int main()
{
    return 0;
}
