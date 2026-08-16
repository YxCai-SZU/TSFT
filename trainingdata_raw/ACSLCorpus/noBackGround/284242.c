#include <limits.h>

/*@
    requires (1 <= (n) <= 20 &&
        1 <= (a) <= 50 &&
        1 <= (b) <= 50);
    ensures \result == a * n || \result == b;
    ensures \result <= b;
    ensures \result <= a * n;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int ret;
    int product;

    //@ assert (1 <= (n) <= 20 &&         1 <= (a) <= 50 &&         1 <= (b) <= 50);
    
    product = a * n;
    //@ assert product == ((a) * (n));
    
    if (product < b)
    {
        ret = product;
    }
    else
    {
        ret = b;
    }
    
    //@ assert ret == a * n || ret == b;
    //@ assert ret <= b;
    //@ assert ret <= a * n;
    
    return ret;
}
