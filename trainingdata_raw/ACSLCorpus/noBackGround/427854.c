#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) * (m) - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int product;
    int result;
    
    //@ assert n * m <= 10000;
    product = n * m;
    
    //@ assert product - 1 <= 9999;
    result = product - 1;
    
    return result;
}
