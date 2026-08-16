#include <stdbool.h>
/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result <= n + m;
*/
int func(int n, int m, int a, int b)
{
    int min_val;
    int result;

    //@ assert 1 <= n <= 100 && 1 <= m <= 100 && 1 <= a <= 100 && 1 <= b <= 100;
    
    if (n + m < a)
    {
        min_val = n + m;
    }
    else
    {
        min_val = a;
    }
    
    //@ assert (((n) + (m) < (a) ==> (min_val) == (n) + (m)) &&         ((n) + (m) >= (a) ==> (min_val) == (a)) &&         (min_val) >= 0 &&         (min_val) <= (n) + (m));
    
    if (b < min_val)
    {
        result = b;
    }
    else
    {
        result = min_val;
    }
    
    //@ assert ((result) >= 0 &&         (result) <= (b) &&         (result) <= (n) + (m));
    return result;
}
