#include <limits.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 1439;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int func(int h1, int m1, int h2, int m2, int k) {
    int start;
    int end;
    int result;

    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    //@ assert (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    
    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    
    //@ assert start == ((h1) * 60 + (m1));
    //@ assert end == ((h2) * 60 + (m2));
    //@ assert end - start >= 0;
    
    result = end - start - k;
    
    //@ assert result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    return result;
}
