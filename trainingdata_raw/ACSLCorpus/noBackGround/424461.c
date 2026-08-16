#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((((n)) * ((m))) - (((n)) + ((m)) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int product;
    int sum;
    int adjusted_sum;
    int result;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    
    //@ assert n * m <= 400;
    product = n * m;
    
    sum = n + m;
    adjusted_sum = sum - 1;
    
    //@ assert product >= 0;
    //@ assert adjusted_sum >= 0;
    
    result = product - adjusted_sum;
    return result;
}
