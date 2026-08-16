#include <stdbool.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == (a % k == 0 || b % k == 0 || b / k > a / k);
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int a_div_k;
    unsigned int b_div_k;
    bool result;
    
    //@ assert a / k <= 1000;
    //@ assert b / k <= 1000;
    
    a_div_k = a / k;
    b_div_k = b / k;
    
    if (a % k == 0 || b % k == 0)
    {
        result = true;
    }
    else if (b_div_k > a_div_k)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
