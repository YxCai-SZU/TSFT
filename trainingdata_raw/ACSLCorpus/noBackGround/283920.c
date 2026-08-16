#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * (n + 1) / 2;
    assigns \nothing;
*/
int func(int n)
{
    int sum;
    int x;
    
    sum = 0;
    x = 1;
    
    /*@
        loop invariant 1 <= x <= n + 1;
        loop invariant sum == (x - 1) * x / 2;
        loop invariant sum >= 0;
        loop assigns sum, x;
        loop variant n - x + 1;
    */
    while (x <= n)
    {
        //@ assert 0 <= x * (x + 1) <= 100 * 101;
        //@ assert sum + x >= 0;
        //@ assert sum + x == x * (x + 1) / 2;
        
        sum += x;
        x += 1;
    }
    
    //@ assert sum == n * (n + 1) / 2;
    return sum;
}
