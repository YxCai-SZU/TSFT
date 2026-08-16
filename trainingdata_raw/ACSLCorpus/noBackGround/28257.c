#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
 */
bool func(int a, int b, int c)
{
    int cnt = 0;

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if (a == b)
    {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0);

    if (a == c)
    {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (a == c ? 1 : 0);

    if (b == c)
    {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (a == c ? 1 : 0) + (b == c ? 1 : 0);

    bool ans = (cnt == 1);
    //@ assert ans == true <==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));

    return ans;
}
