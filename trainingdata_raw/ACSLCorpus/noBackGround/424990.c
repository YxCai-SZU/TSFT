#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    ensures \result == a || \result == b || \result == c;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    
    if (a == b)
    {
        ans = c;
    }
    else if (a == c)
    {
        ans = b;
    }
    else
    {
        ans = a;
    }
    
    //@ assert ans == a || ans == b || ans == c;
    return ans;
}
