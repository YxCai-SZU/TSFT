#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000000000000);
    requires (1 <= (b) && (b) <= 1000000000000000000);
    requires (1 <= (k) && (k) <= 1000000000000000000);
    requires ((a) <= (b));
    ensures \result == (a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k);
*/
bool func(unsigned long long k, unsigned long long a, unsigned long long b)
{
    unsigned long long a_mod_k;
    unsigned long long b_mod_k;
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 1000000000000000000);
    //@ assert (1 <= (b) && (b) <= 1000000000000000000);
    //@ assert (1 <= (k) && (k) <= 1000000000000000000);
    //@ assert ((a) <= (b));
    
    if (a % k == 0 || b % k == 0)
    {
        result = true;
        //@ assert a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k;
        return result;
    }
    else if (b - a >= k)
    {
        result = true;
        //@ assert a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k;
        return result;
    }
    else
    {
        a_mod_k = a % k;
        b_mod_k = b % k;
        
        if (a_mod_k > b_mod_k)
        {
            result = true;
            //@ assert a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k;
            return result;
        }
        else
        {
            //@ assert b - a < k && a_mod_k <= b_mod_k;
            result = false;
            //@ assert !(a % k == 0 || b % k == 0 || b - a >= k || a % k > b % k);
            return result;
        }
    }
}
