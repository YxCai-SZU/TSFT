#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures (1 <= (\result) && (\result) <= 3);
    ensures ((\result) == 1 ==> ((a) == (b) && (b) == (c)));
    ensures ((\result) == 2 ==> (
            ((a) == (b) && (b) != (c)) ||
            ((a) == (c) && (b) != (c)) ||
            ((a) != (b) && (b) == (c))
        ));
    ensures ((\result) == 3 ==> ((a) != (b) && (b) != (c) && (a) != (c)));
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);

    if (a == b && b == c)
    {
        result = 1;
        //@ assert ((result) == 1 ==> ((a) == (b) && (b) == (c)));
    }
    else if (a != b && b != c && c != a)
    {
        result = 3;
        //@ assert ((result) == 3 ==> ((a) != (b) && (b) != (c) && (a) != (c)));
    }
    else
    {
        result = 2;
        //@ assert ((result) == 2 ==> (             ((a) == (b) && (b) != (c)) ||             ((a) == (c) && (b) != (c)) ||             ((a) != (b) && (b) == (c))         ));
    }

    //@ assert (1 <= (result) && (result) <= 3);
    return result;
}
