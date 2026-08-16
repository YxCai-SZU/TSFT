#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) && 0 <= (b) <= (n));
    ensures \result == true <==> n >= a + b;
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    int x;
    bool result;
    
    //@ assert 0 <= a + b <= 2 * n;
    
    x = n - a - b;
    
    if (x >= 0 && x <= n) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> n >= a + b;
    
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant result == true <==> n >= a + b;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        i = i + 1;
    }
    
    return result;
}
