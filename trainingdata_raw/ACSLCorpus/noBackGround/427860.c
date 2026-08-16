#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (r) && (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
int func(int n, int r)
{
    int sub;
    int add;
    int res;

    sub = 10 - n;
    //@ assert sub == 10 - n;

    if (n >= 10)
    {
        res = r;
        //@ assert n >= 10;
        //@ assert res == r;
    }
    else
    {
        //@ assert n < 10;
        add = r + sub * 100;
        //@ assert add == r + 100 * (10 - n);
        res = add;
    }

    //@ assert res == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    return res;
}
