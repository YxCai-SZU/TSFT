#include <stddef.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures 0 <= \result < 1000;
    ensures \result == ((1000 - (((n)) % 1000)) % 1000);
*/
size_t func(size_t n)
{
    size_t n_mod_1000;
    size_t result;
    size_t final_result;
    
    n_mod_1000 = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= n_mod_1000 <= n;
        loop invariant n_mod_1000 == n - 1000 * ((n - n_mod_1000) / 1000);
        loop assigns n_mod_1000;
        loop variant n_mod_1000;
    */
    while (n_mod_1000 >= 1000)
    {
        n_mod_1000 -= 1000;
    }
    
    // Note: In C with unsigned types, n_mod_1000 < 0 is always false
    // The second while loop from Verus is omitted as it's unreachable for unsigned
    
    if (n_mod_1000 == 0)
    {
        result = 0;
    }
    else
    {
        result = 1000 - n_mod_1000;
    }
    
    final_result = result;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= final_result <= result;
        loop invariant final_result == result - 1000 * ((result - final_result) / 1000);
        loop assigns final_result;
        loop variant final_result;
    */
    while (final_result >= 1000)
    {
        final_result -= 1000;
    }
    
    // Note: In C with unsigned types, final_result < 0 is always false
    // The second while loop from Verus is omitted as it's unreachable for unsigned
    
    //@ assert final_result == ((1000 - (((n)) % 1000)) % 1000);
    
    return final_result;
}

int main(void)
{
    return 0;
}
