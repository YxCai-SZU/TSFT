#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int m = 0;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    if (a == b && b == c) {
        m = 1;
    } else if (a != b && b != c && c != a) {
        m = 3;
    } else {
        m = 2;
    }
    
    //@ assert m >= 1 && m <= 3;
    return m;
}
