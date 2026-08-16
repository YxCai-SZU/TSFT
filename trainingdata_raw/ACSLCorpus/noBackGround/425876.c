#include <stdbool.h>

/*@
    requires (0 <= (a) < (b) < (c) < (d) < (e) < 123);
    requires (0 <= (k) <= 123);
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;
    
    //@ assert a < e;
    dist = e - a;
    
    if (dist > k) {
        //@ assert dist > k;
        return false;
    } else {
        //@ assert dist <= k;
        return true;
    }
}
