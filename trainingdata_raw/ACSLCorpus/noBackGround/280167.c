#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((c) + (a) == (b)));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool f = false;

    //@ assert a + b == c ==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((c) + (a) == (b)));
    if (a + b == c)
    {
        f = true;
    }
    else
    {
        //@ assert b + c == a ==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((c) + (a) == (b)));
        if (b + c == a)
        {
            f = true;
        }
        else
        {
            //@ assert c + a == b ==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((c) + (a) == (b)));
            if (c + a == b)
            {
                f = true;
            }
        }
    }

    //@ assert f == true <==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((c) + (a) == (b)));
    return f;
}
