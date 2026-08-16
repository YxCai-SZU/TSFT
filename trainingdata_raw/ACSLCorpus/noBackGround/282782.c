#include <stdbool.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == true <==> (a % k == 0 || b % k == 0 || b / k > a / k);
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    // Precondition assertions
    //@ assert a <= 1000;
    //@ assert b <= 1000;
    //@ assert k <= 1000;
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert k >= 1;
    
    if (a % k == 0 || b % k == 0)
    {
        //@ assert a % k == 0 || b % k == 0 || b / k > a / k;
        result = true;
    }
    else if (b / k > a / k)
    {
        //@ assert a % k == 0 || b % k == 0 || b / k > a / k;
        result = true;
    }
    else
    {
        //@ assert !(a % k == 0 || b % k == 0 || b / k > a / k);
        result = false;
    }
    
    return result;
}
