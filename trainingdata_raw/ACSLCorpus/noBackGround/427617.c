#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int product;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert ((a) * (b)) <= INT_MAX;
    
    product = a * b;
    
    //@ assert product == ((a) * (b));
    
    return product;
}
