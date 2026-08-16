#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result >= 0 && \result <= 3;
    ensures \result == 1 ==> (a == b || b == c || a == c);
    ensures \result == 2 ==> ((a == b && c != a) || (b == c && a != b) || (a == c && b != a));
    ensures \result == 3 ==> (a == b && b == c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = -1;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    
    if (a == b && b == c) {
        //@ assert a == b && b == c;
        ans = 3;
    } else if (a != b && b != c && c != a) {
        //@ assert a != b && b != c && c != a;
        ans = 0;
    } else {
        //@ assert (a == b && c != a) || (b == c && a != b) || (a == c && b != a);
        ans = 2;
    }

    //@ assert ans >= 0 && ans <= 3;
    //@ assert ans == 1 ==> (a == b || b == c || a == c);
    //@ assert ans == 2 ==> ((a == b && c != a) || (b == c && a != b) || (a == c && b != a));
    //@ assert ans == 3 ==> (a == b && b == c);
    
    return ans;
}
