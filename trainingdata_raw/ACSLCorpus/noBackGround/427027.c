#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (r) && (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
int func(int n, int r)
{
    unsigned int n_unsigned;
    unsigned int r_unsigned;
    int res;

    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (r) && (r) <= 4111);
    
    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }
    
    if (r < 0) {
        r_unsigned = (unsigned int)(-r);
    } else {
        r_unsigned = (unsigned int)r;
    }

    if (n < 10) {
        //@ assert n < 10;
        res = r + 100 * (10 - n);
        //@ assert res == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
        return res;
    } else {
        //@ assert n >= 10;
        res = r;
        //@ assert res == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
        return res;
    }
}
