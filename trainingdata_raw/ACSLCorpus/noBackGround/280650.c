#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    int result;
    result = r;
    //@ assert (1 <= (r) <= 100);
    if (r != 0)
    {
        //@ assert ((r) * (r)) <= 10000;
        result = r * r;
    }
    //@ assert result == ((r) * (r));
    return result;
}

/*@
    requires (1 <= (n) <= 100) && (1 <= (m) <= 100);
    ensures \result == ((n) * (m));
    assigns \nothing;
*/
int func2(int n, int m)
{
    int result;
    result = n;
    //@ assert (1 <= (n) <= 100) && (1 <= (m) <= 100);
    if (n != 0 && m != 0)
    {
        //@ assert ((n) * (m)) <= 10000;
        result = n * m;
    }
    //@ assert result == ((n) * (m));
    return result;
}
