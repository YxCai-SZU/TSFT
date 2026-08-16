#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int sum;
    //@ ghost int original_k = k;
    //@ ghost int original_x = x;

    sum = 500 * k;

    //@ assert sum == (500 * (k));
    //@ assert sum == 500 * original_k;

    if (sum >= x)
    {
        //@ assert sum >= x;
        //@ assert (500 * (k)) >= x;
        return true;
    }
    else
    {
        //@ assert !(sum >= x);
        //@ assert (500 * (k)) < x;
        return false;
    }
}
