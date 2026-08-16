#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 200;
    ensures \result == (x <= a + b && x >= a);
*/
bool func(int a, int b, int x)
{
    bool result;
    //@ assert ((1) <= (a) && (a) <= (100));
    //@ assert ((1) <= (b) && (b) <= (100));
    //@ assert ((1) <= (x) && (x) <= (200));
    
    if (x <= a + b && x >= a)
    {
        //@ assert x <= ((a) + (b)) && x >= a;
        result = true;
    }
    else
    {
        //@ assert !(x <= ((a) + (b)) && x >= a);
        result = false;
    }
    
    return result;
}
