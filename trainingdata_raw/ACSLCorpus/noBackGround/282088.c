#include <stdbool.h>

/*@
    requires ((1) <= (a) && (a) <= (100));
    requires ((1) <= (b) && (b) <= (100));
    requires ((1) <= (x) && (x) <= (200));
    ensures \result == (a <= x && a + b >= x);
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    unsigned int sum;

    //@ assert ((1) <= (a) && (a) <= (100));
    //@ assert ((1) <= (b) && (b) <= (100));
    //@ assert ((1) <= (x) && (x) <= (200));

    if (x < a)
    {
        //@ assert !(a <= x && a + b >= x);
        result = false;
    }
    else
    {
        sum = a + b;
        if (x <= sum)
        {
            //@ assert a <= x && a + b >= x;
            result = true;
        }
        else
        {
            //@ assert !(a <= x && a + b >= x);
            result = false;
        }
    }

    //@ assert result == (a <= x && a + b >= x);
    return result;
}
