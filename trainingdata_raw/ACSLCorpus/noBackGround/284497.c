#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result == ((b) - (a) * 2) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    int ret;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    res = b - a * 2;
    
    //@ assert res == ((b) - (a) * 2);
    
    if (res < 0)
    {
        ret = 0;
        //@ assert ret == 0;
    }
    else
    {
        ret = res;
        //@ assert ret == res;
    }
    
    //@ assert ret == ((((b)) - ((a)) * 2) < 0 ? 0 : (((b)) - ((a)) * 2));
    //@ assert ret >= 0;
    //@ assert ret <= b;
    //@ assert ret == ((b) - (a) * 2) || ret == 0;
    
    return ret;
}
