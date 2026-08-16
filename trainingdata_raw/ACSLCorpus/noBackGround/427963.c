#include <stdbool.h>

/*@
    requires (0 <= (a) < (b) < (c) < (d) < (e) <= 123);
    requires (0 <= (k) <= 123);
    ensures \result == true <==> ((e) - (a)) <= k;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert e >= a;
    //@ assert ((e) - (a)) >= 0;
    
    if (e - a <= k)
    {
        result = true;
    }
    else
    {
        //@ assert ((e) - (a)) > k;
        result = false;
    }
    
    return result;
}
