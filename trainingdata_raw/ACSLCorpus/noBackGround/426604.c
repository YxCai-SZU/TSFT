#include <limits.h>

/*@
    requires 0 <= n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert 0 <= n && n <= 100;
    //@ assert 0 <= n * n && n * n <= 10000;
    
    return n * n;
}

int main()
{
    //@ assert ((((10)) % 2 == 0) && (10) > 0);
    //@ assert !((((11)) % 2 == 0) && (11) > 0);
    //@ assert ((((100)) % 2 == 0) && (100) > 0);
    
    int result = func(50);
    //@ assert result == 2500;
    
    return 0;
}
