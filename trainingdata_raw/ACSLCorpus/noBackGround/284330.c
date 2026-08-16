#include <stdbool.h>

/*@
    requires \true;
    ensures (x <= 0 ==> \result == 0) && (x > 0 ==> \result == 1);
*/
int func(int x)
{
    int result;
    
    //@ assert \true;
    
    if (x > 0) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert (x <= 0 ==> result == 0) && (x > 0 ==> result == 1);
    return result;
}
