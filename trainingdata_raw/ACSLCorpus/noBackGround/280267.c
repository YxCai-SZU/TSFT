#include <limits.h>

/*@
    requires ((n) * (n) <= INT_MAX);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
int square(int n)
{
    int ret;
    
    //@ assert ((n) * (n) <= INT_MAX);
    //@ assert ((n) * (n)) >= 0;
    //@ assert ((n) * (n)) <= INT_MAX;
    
    ret = n * n;
    
    //@ assert ret == ((n) * (n));
    return ret;
}

int main()
{
    return 0;
}
