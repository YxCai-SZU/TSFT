#include <stdbool.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == true <==> (a == b || (b / k != a / k && b / k > a / k));
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    bool result;

    if (a == b)
    {
        result = true;
        //@ assert ((a) == (b));
    }
    else if (b / k > a / k)
    {
        result = true;
        //@ assert ((b) / (k) > (a) / (k));
    }
    else
    {
        result = false;
        //@ assert a != b && b / k <= a / k;
    }

    //@ assert ((result) == ((a) == (b) || ((b) / (k) != (a) / (k) && (b) / (k) > (a) / (k))));
    return result;
}
