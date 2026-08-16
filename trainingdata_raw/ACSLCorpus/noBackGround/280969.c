#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == true <==> 500 * k >= x;
*/
bool func(int k, int x)
{
    int sum = 0;
    int i = 0;
    
    /*@
        loop invariant (1 <= (k) <= 100 &&
        1 <= (x) <= 100000 &&
        (sum) == 500 * (i) &&
        (i) <= (k) &&
        (sum) <= 500 * (k));
        loop assigns sum, i;
    */
    while (i < k)
    {
        sum += 500;
        i += 1;
    }
    
    //@ assert sum == 500 * k;
    return sum >= x;
}
