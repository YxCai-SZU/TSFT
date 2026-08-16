#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (a > c ? (c > d ? true : false) : (b > c ? true : false));
    assigns \nothing;
*/
bool can_communicate(int a, int b, int c, int d)
{
    bool result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a > c)
    {
        //@ assert a > c;
        //@ assert (1 <= (c) <= 10000);
        if (c > d)
        {
            //@ assert a > c && c > d;
            result = true;
        }
        else
        {
            //@ assert a > c && !(c > d);
            result = false;
        }
    }
    else
    {
        //@ assert !(a > c);
        //@ assert (1 <= (b) <= 10000);
        if (b > c)
        {
            //@ assert !(a > c) && b > c;
            result = true;
        }
        else
        {
            //@ assert !(a > c) && !(b > c);
            result = false;
        }
    }

    return result;
}
