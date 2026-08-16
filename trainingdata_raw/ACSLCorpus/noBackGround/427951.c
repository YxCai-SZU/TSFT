#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);
    requires ((a) == (b) || (b) == (c) || (a) == (c));
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 2 ==> ((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c));
    ensures \result == 3 ==> ((a) != (b) && (b) != (c) && (a) != (c));
*/
int func(int a, int b, int c)
{
    int ans;
    
    //@ assert ((a) == (b) || (b) == (c) || (a) == (c));
    
    if (a == b && b == c) {
        ans = 1;
        //@ assert ((a) == (b) && (b) == (c));
    } else if (a != b && b != c && a != c) {
        ans = 3;
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
    } else {
        ans = 2;
        //@ assert ((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c));
    }
    
    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
