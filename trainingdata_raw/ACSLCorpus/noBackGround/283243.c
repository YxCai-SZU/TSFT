#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000);
    ensures \result == true <==> 500 * k >= x;
    assigns \nothing;
*/
bool func(int k, int x)
{
    // Variable declarations at scope top
    int sum;

    //@ assert (1 <= (k) && (k) <= 100 &&         1 <= (x) && (x) <= 100000);
    
    //@ assert 500 * k >= 500;
    //@ assert 500 * k <= 50000;

    sum = 500 * k;
    
    if (sum >= x) {
        return true;
    } else {
        return false;
    }
}
