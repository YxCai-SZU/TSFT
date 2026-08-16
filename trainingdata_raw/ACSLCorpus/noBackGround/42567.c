#include <limits.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top
    int res;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert a + (a * a) <= 10 + (10 * 10);
    
    //@ assert a * a * a <= 10 * 10 * 10;
    
    //@ assert a + (a * a) + (a * a * a) <= 10 + (10 * 10) + (10 * 10 * 10);
    
    res = a + (a * a) + (a * a * a);
    
    //@ assert res == a + (a * a) + (a * a * a);
    
    return res;
}

int main()
{
    return 0;
}
