#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures (((n) % 2 == 0) ==> \result == 1) && (((n) % 2 != 0) ==> \result == 1);
    assigns \nothing;
*/
int func(int n)
{
    int result = 1;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant result == 1;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        i = i + 1;
    }
    
    //@ assert result == 1;
    return result;
}
