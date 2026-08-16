#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    
    //@ assert (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    
    if (a == b)
    {
        ans += 1;
    }
    if (b == c)
    {
        ans += 1;
    }
    if (c == a)
    {
        ans += 1;
    }
    
    //@ assert 0 <= ans <= 3;
    
    if (ans == 3)
    {
        //@ assert a == b && b == c;
        return 1;
    }
    else if (ans == 0)
    {
        //@ assert a != b && b != c && a != c;
        return 3;
    }
    else
    {
        //@ assert (a == b && a != c) || (b == c && b != a) || (c == a && c != b);
        return 2;
    }
}
