#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a != b && a == c) ==> \result == b;
    ensures (a == c && a != b) ==> \result == b;
    ensures (a == b && a == c) ==> \result == a;
    ensures (a != b && b == c) ==> \result == a;
    ensures \result == (((a) == (b) && (a) != (c)) ? (c) :
        ((a) != (b) && (a) == (c)) ? (b) :
        ((a) == (c) && (a) != (b)) ? (b) :
        ((a) == (b) && (a) == (c)) ? (a) :
        ((a) != (b) && (b) == (c)) ? (a) :
        0);
*/
int func(int a, int b, int c)
{
    int result = 0;
    
    if (a == b)
    {
        if (a == c)
        {
            //@ assert a == b && a == c;
            result = a;
        }
        else
        {
            //@ assert a == b && a != c;
            result = c;
        }
    }
    else if (a == c)
    {
        //@ assert a != b && a == c;
        result = b;
    }
    else if (b == c)
    {
        //@ assert a != b && b == c;
        result = a;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        result = 0;
    }
    
    //@ assert result == (((a) == (b) && (a) != (c)) ? (c) :         ((a) != (b) && (a) == (c)) ? (b) :         ((a) == (c) && (a) != (b)) ? (b) :         ((a) == (b) && (a) == (c)) ? (a) :         ((a) != (b) && (b) == (c)) ? (a) :         0);
    return result;
}
