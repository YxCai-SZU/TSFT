#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == true <==> 
            (((b) - (a) <= (k)) && ((c) - (a) <= (k)) && 
             ((d) - (a) <= (k)) && ((e) - (a) <= (k)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    // Variable declarations at scope top
    bool result;

    if (b - a > k) {
        return false;
    }
    //@ assert ((b) - (a) <= (k));
    
    if (c - a > k) {
        return false;
    }
    //@ assert ((c) - (a) <= (k));
    
    if (d - a > k) {
        return false;
    }
    //@ assert ((d) - (a) <= (k));
    
    if (e - a > k) {
        return false;
    }
    //@ assert ((e) - (a) <= (k));
    
    result = true;
    return result;
}
