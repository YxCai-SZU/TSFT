#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == ((n) / 500) * 1000 + (((n) % 500) / 5) * 5;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t res = 0;
    size_t temp_n = n;
    size_t n_div_500 = 0;
    size_t n_mod_500_div_5 = 0;
    
    //@ assert (1 <= (n) && (n) <= 10000);
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant n_div_500 <= ((n) / 500);
        loop invariant temp_n == n - 500 * n_div_500;
        loop invariant (1 <= (n) && (n) <= 10000);
        loop assigns temp_n, n_div_500;
        loop variant temp_n;
    */
    while (temp_n >= 500)
    {
        //@ assert temp_n >= 500;
        temp_n -= 500;
        n_div_500 += 1;
        //@ assert n_div_500 <= ((n) / 500);
    }
    
    //@ assert temp_n == ((n) % 500);
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant n_mod_500_div_5 <= (((n) % 500) / 5);
        loop invariant temp_n == n - 500 * n_div_500 - 5 * n_mod_500_div_5;
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant n_div_500 <= ((n) / 500);
        loop assigns temp_n, n_mod_500_div_5;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert temp_n >= 5;
        temp_n -= 5;
        n_mod_500_div_5 += 1;
        //@ assert n_mod_500_div_5 <= (((n) % 500) / 5);
    }
    
    //@ assert temp_n == ((n) % 500) - 5 * (((n) % 500) / 5);
    //@ assert n_mod_500_div_5 == (((n) % 500) / 5);
    
    res = n_div_500 * 1000 + n_mod_500_div_5 * 5;
    
    //@ assert res == ((n) / 500) * 1000 + (((n) % 500) / 5) * 5;
    return res;
}

int main(void)
{
    return 0;
}
