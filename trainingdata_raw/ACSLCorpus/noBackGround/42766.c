#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (a) <= 100 && 1 <= (b) <= 200);
    ensures \result == (b - n * a >= 0);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 200;
    //@ assert n * a <= 10000;
    
    return b - n * a >= 0;
}
