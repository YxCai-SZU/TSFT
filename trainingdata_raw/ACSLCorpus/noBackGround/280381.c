#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000 &&
        500 * (k) <= 1000000000);
    ensures \result == ((500 * (k)) >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int sum;
    //@ assert (500 * (k)) <= 1000000000;
    sum = 500 * k;
    
    if (sum >= x)
    {
        //@ assert (500 * (k)) >= x;
        return true;
    }
    else
    {
        //@ assert !((500 * (k)) >= x);
        return false;
    }
}
