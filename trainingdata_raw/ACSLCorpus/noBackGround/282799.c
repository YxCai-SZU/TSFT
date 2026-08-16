#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    //@ assert n > 1 && n <= 100;
    //@ assert m > 1 && m <= 100;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert n - 1 <= 99;
    //@ assert m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 9801;
    //@ assert (n - 1) * (m - 1) >= 1;
    
    return (n - 1) * (m - 1);
}
