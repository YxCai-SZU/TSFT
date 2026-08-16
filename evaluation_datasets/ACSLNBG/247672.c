#include <limits.h>


int func(int a, int b)
{
    int ans = 1;
    
    //@ assert 1 <= a - 1 <= 99;
    ans *= a - 1;
    
    //@ assert 1 <= ans * (b - 1) <= 99 * 99;
    ans *= b - 1;
    
    return ans;
}
