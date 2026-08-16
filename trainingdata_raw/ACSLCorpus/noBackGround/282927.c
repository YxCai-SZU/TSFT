#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (white) <= (n) * (n));
    ensures \result == ((n) * (n) - (white));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t white)
{
    int32_t black;
    
    //@ assert white >= 0 && white <= n * n;
    //@ assert n * n >= 0;
    //@ assert n * n <= 10000;
    
    black = n * n - white;
    return black;
}
