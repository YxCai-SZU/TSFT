#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= k <= 3;
    ensures \result == true <==> (k == 1 || a >= k || (a + b) >= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int k)
{
    bool result;
    // Variable declarations at scope top
    result = false;

    if (k == 1)
    {
        result = true;
        //@ assert result == true;
        return result;
    }
    else if (a >= k)
    {
        result = true;
        //@ assert result == true;
        return result;
    }
    else if ((a + b) >= k)
    {
        result = true;
        //@ assert result == true;
        return result;
    }

    //@ assert k != 1 && a < k && (a + b) < k;
    result = false;
    //@ assert result == false;
    return result;
}
