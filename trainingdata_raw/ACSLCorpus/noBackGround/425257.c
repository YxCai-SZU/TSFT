#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == ((500 * (k)) >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int max;
    
    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    
    max = 500 * k;
    
    //@ assert max == (500 * (k));
    //@ assert max >= 0;
    //@ assert max <= 50000;
    
    return max >= x;
}
