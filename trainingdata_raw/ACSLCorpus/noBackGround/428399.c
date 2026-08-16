#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    requires ((a) != (b));
    ensures \result == ((a <= n && b > n) || (a > n && b <= n));
*/
bool func(int n, int a, int b)
{
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    //@ assert a != b;
    
    return (a <= n && b > n) || (a > n && b <= n);
}
