#include <stdint.h>


int32_t func(int32_t A, int32_t B, int32_t C, int32_t K)
{
    int32_t res;
    int32_t rst;
    
    res = 0;
    rst = K;
    
    if (A >= rst)
    {
        res += rst;
    }
    else
    {
        res += A;
    }
    
    rst -= A;
    
    if (rst <= 0)
    {
        //@ assert res >= -C;
        //@ assert res <= A;
        return res;
    }
    
    rst -= B;
    
    if (rst <= 0)
    {
        //@ assert res >= -C;
        //@ assert res <= A;
        return res;
    }
    
    res -= rst;
    rst = 0;
    
    //@ assert res >= -C;
    //@ assert res <= A;
    return res;
}
