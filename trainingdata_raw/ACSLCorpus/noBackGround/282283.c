#include <stdbool.h>

/*@
    requires -1000 <= a <= 1000;
    requires -1000 <= b <= 1000;
    ensures ((a) >= 0 && (b) >= 0) ==> \result == a + b;
    ensures !((a) >= 0 && (b) >= 0) ==> \result == 0;
*/
int func(int a, int b)
{
    int sum;
    int res;
    
    sum = a + b;
    
    if (a >= 0 && b >= 0)
    {
        res = sum;
        //@ assert ((a) >= 0 && (b) >= 0) && res == a + b;
    }
    else
    {
        res = 0;
        //@ assert !((a) >= 0 && (b) >= 0) && res == 0;
    }
    
    return res;
}
