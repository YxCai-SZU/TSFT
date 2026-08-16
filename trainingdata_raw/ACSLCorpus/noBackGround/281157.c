#include <limits.h>

/*@
    requires (-100 <= (a) <= 100);
    requires (-100 <= (b) <= 100);
    requires (-100 <= (c) <= 100);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    
    if (a == b)
    {
        result = c;
    }
    else if (a == c)
    {
        result = b;
    }
    else if (b == c)
    {
        result = a;
    }
    else
    {
        //@ assert (-100 <= (a) <= 100);
        //@ assert (-100 <= (b) <= 100);
        //@ assert (-100 <= (c) <= 100);
        //@ assert -1000000 <= ((a) * (b) * (c)) <= 1000000;
        result = 0;
    }
    
    return result;
}
