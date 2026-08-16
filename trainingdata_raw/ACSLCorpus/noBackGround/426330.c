#include <stdbool.h>

/*@
    requires (1 <= (n) && 1 <= (m) && 0 <= (k) &&
        (n) <= 100000 && (m) <= 100000 && (k) <= (n));
    ensures \result == (n == k || m == k || n + m - k >= 2);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (n) && 1 <= (m) && 0 <= (k) &&         (n) <= 100000 && (m) <= 100000 && (k) <= (n));
    
    //@ assert ((n) + (m)) <= 200000;
    
    if (n == k || m == k)
    {
        result = true;
    }
    else if (n + m - k >= 2)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
