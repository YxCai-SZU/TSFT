#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (c) <= 20) && (1 <= (d) <= 20);
    ensures (1 <= (\result) <= 20);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int max_result;

    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    if (a > b)
    {
        max_ab = a;
    }
    else
    {
        max_ab = b;
    }
    //@ assert (1 <= (max_ab) <= 20);

    //@ assert (1 <= (c) <= 20) && (1 <= (d) <= 20);
    if (c > d)
    {
        max_cd = c;
    }
    else
    {
        max_cd = d;
    }
    //@ assert (1 <= (max_cd) <= 20);

    //@ assert (1 <= (max_ab) <= 20) && (1 <= (max_cd) <= 20);
    if (max_ab > max_cd)
    {
        max_result = max_ab;
    }
    else
    {
        max_result = max_cd;
    }
    //@ assert (1 <= (max_result) <= 20);

    return max_result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    int a = 3;
    int b = 5;
    int c = 2;
    int d = 7;
    int result = func(a, b, c, d);
    //@ assert result == 7;
    assert(result == 7);
    return 0;
}
#endif
