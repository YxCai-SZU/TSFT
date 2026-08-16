#include <stdbool.h>

/*@
    requires a < 124 && b < 124 && c < 124 && d < 124 && e < 124;
    requires a <= b && b <= c && c <= d && d <= e;
    requires k <= 123;
    ensures \result == true <==> (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int diff;
    
    // Calculate absolute difference
    if (a > e) {
        diff = a - e;
    } else {
        diff = e - a;
    }
    
    //@ assert ((diff) == ((a) > (e) ? (a) - (e) : (e) - (a)));
    
    if (diff <= k) {
        //@ assert diff <= k;
        return true;
    } else {
        //@ assert diff > k;
        return false;
    }
}
