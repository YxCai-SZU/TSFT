#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int result;
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    //@ assert n * a <= 1000;
    
    if (n * a < b)
    {
        result = n * a;
    }
    else
    {
        result = b;
    }
    
    //@ assert result == n * a || result == b;
    //@ assert result <= b;
    return result;
}
