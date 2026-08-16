#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
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
        //@ assert a == b && a != c ==> result == c;
        return result;
    }
    else if (a == c)
    {
        result = b;
        //@ assert a == c && a != b ==> result == b;
        return result;
    }
    else if (b == c)
    {
        result = a;
        //@ assert b == c && a != b ==> result == a;
        return result;
    }
    
    //@ assert -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100;
    result = 0;
    return result;
}
