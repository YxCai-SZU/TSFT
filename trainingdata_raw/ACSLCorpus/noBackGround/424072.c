#include <stdbool.h>

/*@
    requires 1 <= k && k <= 100;
    requires 1 <= x && x <= 100000;
    ensures \result <==> ((k) * 500 >= (x));
*/
bool func(int k, int x)
{
    bool result;
    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    
    if (k * 500 >= x)
    {
        //@ assert ((k) * 500 >= (x));
        result = true;
    }
    else
    {
        //@ assert !((k) * 500 >= (x));
        result = false;
    }
    
    return result;
}
