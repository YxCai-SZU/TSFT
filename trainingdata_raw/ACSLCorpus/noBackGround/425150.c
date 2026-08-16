#include <stdbool.h>

/*@
    requires \true;
    ensures (((\result) == (a) && (a) >= (b)) || ((\result) == (b) && (b) > (a)));
*/
int maximum(int a, int b)
{
    int ret;
    //@ assert \true;
    if (a > b)
    {
        //@ assert a >= b;
        ret = a;
    }
    else
    {
        //@ assert b >= a;
        ret = b;
    }
    //@ assert (((ret) == (a) && (a) >= (b)) || ((ret) == (b) && (b) > (a)));
    return ret;
}
