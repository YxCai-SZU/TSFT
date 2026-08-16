#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (
        (a == b && a != c) ||
        (b == c && a != b) ||
        (c == a && a != b)
    );
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int cnt = 0;

    //@ assert ((cnt) >= 0 && (cnt) <= 3);

    if (a == b)
    {
        cnt += 1;
    }

    //@ assert ((cnt) >= 0 && (cnt) <= 3);

    if (b == c)
    {
        cnt += 1;
    }

    //@ assert ((cnt) >= 0 && (cnt) <= 3);

    if (c == a)
    {
        cnt += 1;
    }

    //@ assert ((cnt) >= 0 && (cnt) <= 3);
    //@ assert cnt == 1 ==> ((a == b && a != c) || (b == c && a != b) || (c == a && a != b));
    
    return cnt == 1;
}
