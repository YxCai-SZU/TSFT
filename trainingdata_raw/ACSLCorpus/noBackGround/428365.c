#include <stdbool.h>

/*@
    requires (1 <= (x) <= 10);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func(int x)
{
    int res;
    
    //@ assert (1 <= (x) <= 10);
    //@ assert ((x) * (x)) <= 100;
    
    res = x * x;
    
    //@ assert res == ((x) * (x));
    return res;
}

int main()
{
    int n;
    
    n = func(3);
    //@ assert n == 9;
    
    return 0;
}
