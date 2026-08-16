#include <stdbool.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1);
    ensures \result == ((a) + (b) + (c));
*/
int func(int a, int b, int c)
{
    //@ assert ((a) >= 1 && (b) >= 1 && (c) >= 1);
    
    int ret;
    
    //@ assert ((a) + (b) + (c)) == a + b + c;
    
    ret = a + b + c;
    
    //@ assert ret == ((a) + (b) + (c));
    
    return ret;
}
