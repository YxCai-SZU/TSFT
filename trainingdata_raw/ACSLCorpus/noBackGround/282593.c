#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((((a)) + ((b))) + (10 * ((c)))) || \result == ((((a)) + ((c))) + (10 * ((b)))) || \result == ((((b)) + ((c))) + (10 * ((a))));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int res1;
    int res2;
    int res3;
    int max_res;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    //@ assert ((a) + (b)) <= 18;
    //@ assert ((a) + (c)) <= 18;
    //@ assert ((b) + (c)) <= 18;
    //@ assert (10 * (c)) <= 90;
    //@ assert (10 * (b)) <= 90;

    res1 = a + b + 10 * c;
    res2 = a + c + 10 * b;
    res3 = b + c + 10 * a;

    //@ assert res1 == ((((a)) + ((b))) + (10 * ((c))));
    //@ assert res2 == ((((a)) + ((c))) + (10 * ((b))));
    //@ assert res3 == ((((b)) + ((c))) + (10 * ((a))));

    if (res1 > res2)
    {
        if (res1 > res3)
        {
            max_res = res1;
        }
        else
        {
            max_res = res3;
        }
    }
    else
    {
        if (res2 > res3)
        {
            max_res = res2;
        }
        else
        {
            max_res = res3;
        }
    }

    //@ assert max_res == res1 || max_res == res2 || max_res == res3;
    return max_res;
}
