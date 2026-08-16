#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int sum;
    bool result;

    //@ assert (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    sum = 500 * k;
    
    //@ assert sum == (500 * (k));
    //@ assert 500 <= sum <= 50000;
    
    if (sum >= x) {
        //@ assert sum >= x;
        result = true;
    } else {
        //@ assert sum < x;
        result = false;
    }
    
    //@ assert result == (sum >= x);
    return result;
}
