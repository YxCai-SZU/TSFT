#include <stdint.h>


int64_t func(int64_t A, int64_t B)
{
    int64_t ans;
    int64_t ret;

    ans = A - 2 * B;
    
    //@ assert ((A) - 2 * (B)) == ans;
    
    if (ans > 0) {
        ret = ans;
        //@ assert ret == ((A) - 2 * (B));
    } else {
        ret = 0;
        //@ assert ret == 0;
    }
    
    //@ assert ret >= 0;
    //@ assert ret == ((A) - 2 * (B)) || ret == 0;
    
    return ret;
}
