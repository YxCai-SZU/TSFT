#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures (a == b && b != c) ==> \result == c;
    ensures (b == c && a != b) ==> \result == a;
    ensures (a == c && a != b) ==> \result == b;
    ensures (-100 <= (\result) <= 100);
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans;
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    
    if (a == b) {
        ans = c;
        //@ assert a == b && ans == c;
    } else if (b == c) {
        ans = a;
        //@ assert b == c && a != b && ans == a;
    } else {
        ans = b;
        //@ assert a != b && b != c && ans == b;
    }
    
    //@ assert (-100 <= (ans) <= 100);
    return ans;
}
