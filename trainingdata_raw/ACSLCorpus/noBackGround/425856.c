#include <stdbool.h>

/*@
    requires (0 <= (a) < (b) < (c) < (d) < (e) <= 123 &&
        0 <= (k) <= 123);
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    // Variable declarations at scope top
    bool ans;
    unsigned int diff;

    //@ assert 0 <= a <= e <= 123;
    diff = e - a;
    
    //@ assert 0 <= diff <= 123;
    //@ assert diff == e - a;
    
    if (diff <= k) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == (e - a <= k);
    return ans;
}
