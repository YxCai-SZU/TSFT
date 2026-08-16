#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t r)
{
    int64_t sub;
    int64_t res;

    sub = 10 - n;
    
    if (n >= 10)
    {
        //@ assert n >= 10;
        res = r;
    }
    else
    {
        //@ assert n < 10;
        res = r + 100 * sub;
    }

    return res;
}
