#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures (a == b && b != c) ==> \result == c;
    ensures (b == c && a != b) ==> \result == a;
    ensures (a == c && b != a) ==> \result == b;
    ensures in_range(\result);
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert in_range(a) && in_range(b) && in_range(c);
    
    if (a == b)
    {
        ans = c;
    }
    else if (b == c)
    {
        ans = a;
    }
    else
    {
        ans = b;
    }
    
    //@ assert ans == c || ans == a || ans == b;
    //@ assert in_range(ans);
    
    //@ assert (a == b && b != c) ==> ans == c;
    //@ assert (b == c && a != b) ==> ans == a;
    //@ assert (a == c && b != a) ==> ans == b;
    
    return ans;
}
