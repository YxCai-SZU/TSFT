#include <stdbool.h>

/*@
    requires n <= 1;
    ensures ((n) == 1) ==> \result == 0;
    ensures ((n) == 0) ==> \result == 1;
*/
int func(unsigned int n)
{
    int ret;
    
    //@ assert n <= 1;
    
    if (n == 1) {
        //@ assert ((n) == 1);
        ret = 0;
    } else {
        //@ assert ((n) == 0);
        ret = 1;
    }
    
    return ret;
}
