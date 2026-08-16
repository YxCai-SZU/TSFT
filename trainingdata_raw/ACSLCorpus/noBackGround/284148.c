#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == ((n + 1) / 2 >= k);
*/
bool func(unsigned long n, unsigned long k)
{
    unsigned long half_n;
    bool result;

    half_n = (n + 1) / 2;
    //@ assert ((half_n) == ((n) + 1) / 2);

    if (half_n < k) {
        result = false;
    } else {
        result = true;
    }

    return result;
}
