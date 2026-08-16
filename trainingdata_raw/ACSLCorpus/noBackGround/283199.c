#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> ((((a)) % 3 == 0) || (((b)) % 3 == 0) || (((a) + (b)) % 3 == 0));
*/
bool func(int a, int b)
{
    bool ret = false;
    
    //@ assert ((((a)) % 3 == 0) || (((b)) % 3 == 0) || (((a) + (b)) % 3 == 0)) ==> (((a) % 3 == 0) || ((b) % 3 == 0) || ((a + b) % 3 == 0));
    
    if ((a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0))
    {
        ret = true;
    }
    
    //@ assert ret == true <==> ((((a)) % 3 == 0) || (((b)) % 3 == 0) || (((a) + (b)) % 3 == 0));
    
    return ret;
}
