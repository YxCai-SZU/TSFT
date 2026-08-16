#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> (a == b || b == c || a == c);
    ensures \result == 3 ==> (a != b && b != c && a != c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int res = -1;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    if (a == b && b == c)
    {
        res = 1;
        //@ assert res == 1 && a == b && b == c;
    }
    else if (a != b && b != c && a != c)
    {
        res = 3;
        //@ assert res == 3 && a != b && b != c && a != c;
    }
    else
    {
        res = 2;
        //@ assert res == 2 && (a == b || b == c || a == c);
    }

    //@ assert res >= 1 && res <= 3;
    return res;
}
