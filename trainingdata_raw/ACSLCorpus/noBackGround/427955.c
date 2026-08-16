#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == a * n || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int max_value;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    //@ assert a * n <= 1000;
    
    if (a * n > b)
    {
        max_value = b;
    }
    else
    {
        max_value = a * n;
    }
    
    //@ assert max_value == a * n || max_value == b;
    //@ assert max_value <= b;
    
    return max_value;
}
