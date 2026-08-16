#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((n) % 2 == 0);
    ensures \result == 0 ==> ((n) % 2 == 1);
*/
int func(int n)
{
    int result;
    int temp_n;
    
    result = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 2 == n % 2;
        loop assigns temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n = temp_n - 2;
    }
    
    if (temp_n == 0)
    {
        result = 1;
    }
    
    return result;
}
