#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (((a) == (b)) && ((a) != (c))) ==> \result == c;
    ensures (((a) == (c)) && ((a) != (b))) ==> \result == b;
    ensures (((b) == (c)) && ((b) != (a))) ==> \result == a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;
    //@ assert -100 <= c <= 100;
    
    if (a == b && a != c)
    {
        //@ assert ((a) == (b)) && ((a) != (c));
        result = c;
    }
    else if (a == c && a != b)
    {
        //@ assert ((a) == (c)) && ((a) != (b));
        result = b;
    }
    else if (b == c && b != a)
    {
        //@ assert ((b) == (c)) && ((b) != (a));
        result = a;
    }
    else
    {
        //@ assert -100 <= a <= 100;
        result = a;
    }
    
    return result;
}
