#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a == b || b == c || a == c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int cnt = 0;

    //@ assert ((a) == (b) || (b) == (c) || (a) == (c)) <==> (a == b || b == c || a == c);

    if (a == b)
    {
        cnt += 1;
    }
    if (b == c)
    {
        cnt += 1;
    }
    if (a == c)
    {
        cnt += 1;
    }

    //@ assert cnt > 0 ==> ((a) == (b) || (b) == (c) || (a) == (c));

    return cnt > 0;
}
