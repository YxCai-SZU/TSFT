#include <stddef.h>

/*@ requires 1 <= n <= 10000;
    ensures \result <= 1000;
    ensures \result == (n % 1000 == 0 ? 0 : 1000 - n % 1000);
 */
size_t func(size_t n)
{
    size_t mo = 1000;
    size_t ret;
    
    if (n % mo == 0) {
        ret = 0;
    } else {
        //@ assert mo - n % mo <= 1000;
        ret = mo - n % mo;
    }
    
    //@ assert ret == (n % mo == 0 ? 0 : mo - n % mo);
    return ret;
}
