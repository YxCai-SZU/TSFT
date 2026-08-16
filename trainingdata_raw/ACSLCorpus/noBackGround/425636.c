#include <stdbool.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == true <==> ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
*/
bool func(int k, int a, int b)
{
    int a_mod_k;
    int b_mod_k;
    bool result;

    a_mod_k = a % k;
    b_mod_k = b % k;

    if (a_mod_k == 0 || b_mod_k == 0)
    {
        result = true;
        //@ assert ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
    else if (b - a >= k)
    {
        result = true;
        //@ assert ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
    else
    {
        //@ assert a_mod_k > b_mod_k || a_mod_k <= b_mod_k;
        result = a_mod_k > b_mod_k;
        //@ assert result == true <==> ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
}
