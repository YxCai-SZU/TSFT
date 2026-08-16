#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100);
    requires (-100 <= (b) <= 100);
    requires (-100 <= (c) <= 100);
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) != (b) && (b) != (c) && (a) != (c)) ? 3 : 2);
    ensures (a == b && b == c) ==> \result == 1;
    ensures (a == b && a != c) ==> \result == 2;
    ensures (a != b && a == c) ==> \result == 2;
    ensures (b == c && a != b) ==> \result == 2;
    ensures (a != b && b != c && a != c) ==> \result == 3;
*/
int func(int a, int b, int c)
{
    int result = 0;

    if (a == b && b == c)
    {
        result = 1;
    }
    else if (a != b && b != c && c != a)
    {
        result = 3;
    }
    else
    {
        result = 2;
    }

    //@ assert (a == b && b == c) ==> result == 1;
    //@ assert (a == b && a != c) ==> result == 2;
    //@ assert (a != b && a == c) ==> result == 2;
    //@ assert (b == c && a != b) ==> result == 2;
    //@ assert (a != b && b != c && a != c) ==> result == 3;

    return result;
}
