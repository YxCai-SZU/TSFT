#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *a)
{
    int broken = 0;
    size_t i = 0;
    
    /*@
        loop invariant ((((n)) >= 1 && ((n)) <= 100000 &&
        \valid(((a)) + (0 .. ((n))-1)) &&
        \forall size_t i; 0 <= i < ((n)) ==> 1 <= ((a))[i] && ((a))[i] <= 100) &&
        0 <= (i) && (i) <= (n) &&
        (broken) >= 0 && (broken) <= (int)(i) &&
        \forall size_t k; 0 <= k < (i) ==> 1 <= (a)[k] && (a)[k] <= 100);
        loop assigns i, broken;
        loop variant n - i;
    */
    while (i < n)
    {
        int value = a[i];
        
        if (value == 1)
        {
            broken += 1;
        }
        else if (broken > 0)
        {
            broken -= 1;
        }
        
        i += 1;
        
        //@ assert i <= n;
    }
    
    return (int)n - broken;
}
