#include <stdint.h>
#include <stddef.h>

/*@
    requires ((n) > 0 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= ((n) * 1000000000);
    assigns \nothing;
*/
int64_t func(size_t n, int64_t *a)
{
    int64_t before = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant ((n) > 0 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
        loop invariant before >= 0;
        loop invariant before <= ((index) * 1000000000);
        loop assigns before, index;
        loop variant n - index;
    */
    while (index < n)
    {
        int64_t ai = a[index];
        //@ assert ai > 0 && ai <= 1000000000;
        
        if (before <= ai)
        {
            before = ai;
        }
        else
        {
            before = ai - 1;
        }
        //@ assert before >= 0;
        index += 1;
    }
    return before;
}
