#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
*/
bool func(int k, int x)
{
    int n = 0;
    int sum = 0;
    
    /*@
        loop invariant 0 <= n <= k;
        loop invariant sum == (500 * (n));
        loop invariant sum <= 500 * k;
        loop assigns n, sum;
    */
    while (n < k)
    {
        //@ assert sum == 500 * n;
        sum += 500;
        n += 1;
        //@ assert sum == 500 * n;
    }
    
    //@ assert sum == 500 * k;
    bool result = (sum >= x);
    //@ assert result == (500 * k >= x);
    return result;
}
