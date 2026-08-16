#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 2 ==> (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
    ensures \result == 3 ==> ((a) != (b) && (b) != (c) && (a) != (c));
*/
int func(long long a, long long b, long long c)
{
    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;
    //@ assert -100 <= c <= 100;
    
    if (a == b && b == c)
    {
        //@ assert ((a) == (b) && (b) == (c));
        return 1;
    }
    else if (a == b || b == c || a == c)
    {
        //@ assert (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
        return 2;
    }
    else
    {
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
        return 3;
    }
}
