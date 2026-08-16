#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n * n;
    ensures \result == n * n - m;
    assigns \nothing;
*/
int func(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    //@ assert n * n <= 10000;
    
    return n * n - m;
}

int main()
{
    return 0;
}
