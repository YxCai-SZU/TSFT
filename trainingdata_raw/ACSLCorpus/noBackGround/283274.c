#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == true <==> (500 * (k) >= (x));
*/
bool func(int k, int x)
{
    int k_local = k;
    int x_local = x;
    bool result;

    //@ assert (500 * (k_local) >= (x_local)) <==> 500 * k_local >= x_local;
    result = (500 * k_local >= x_local);
    return result;
}
