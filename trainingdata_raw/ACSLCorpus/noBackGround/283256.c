#include <stdbool.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == true <==> (((a) == (b)) ||
        (((((b) - (a)) % 2) == 0) && (((a) < (b) && ((b) - (a)) >= (k)) || ((a) > (b) && ((a) - (b)) >= (k)))));
    assigns \nothing;
*/
bool func(int k, int a, int b)
{
    bool result;
    
    //@ assert 1 <= k && k <= 1000;
    
    if (a == b)
    {
        result = true;
        //@ assert (((a) == (b)) ||         (((((b) - (a)) % 2) == 0) && (((a) < (b) && ((b) - (a)) >= (k)) || ((a) > (b) && ((a) - (b)) >= (k)))));
        return result;
    }
    else if ((b - a) % 2 == 0)
    {
        result = (a < b && b - a >= k) || (a > b && a - b >= k);
        //@ assert result == true <==> (((a) == (b)) ||         (((((b) - (a)) % 2) == 0) && (((a) < (b) && ((b) - (a)) >= (k)) || ((a) > (b) && ((a) - (b)) >= (k)))));
        return result;
    }
    else
    {
        //@ assert (b - a) % 2 != 0;
        result = false;
        //@ assert !(((a) == (b)) ||         (((((b) - (a)) % 2) == 0) && (((a) < (b) && ((b) - (a)) >= (k)) || ((a) > (b) && ((a) - (b)) >= (k)))));
        return result;
    }
}
