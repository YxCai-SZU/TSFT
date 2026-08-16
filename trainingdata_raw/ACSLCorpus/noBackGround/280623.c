#include <stdint.h>
#include <limits.h>

/*@
    requires ((n) >= 2 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t *a)
{
    int64_t min = INT64_MAX;
    int64_t i = 0;
    //@ ghost int64_t old_min = min;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant min >= 0;
        loop invariant ((n) >= 2 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
        loop assigns i, min;
        loop variant n - i;
    */
    while (i < n)
    {
        int64_t xor_result = a[i];
        int64_t j = 0;
        //@ ghost int64_t old_xor = xor_result;

        /*@
            loop invariant 0 <= j <= n;
            loop invariant xor_result >= 0;
            loop invariant ((n) >= 2 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
            loop assigns j, xor_result;
            loop variant n - j;
        */
        while (j < n)
        {
            if (i != j)
            {
                int64_t new_xor_result;
                if (xor_result > a[j])
                {
                    new_xor_result = xor_result - a[j];
                }
                else
                {
                    new_xor_result = a[j] - xor_result;
                }
                //@ assert new_xor_result == ((xor_result) > (a[j]) ? (xor_result) - (a[j]) : (a[j]) - (xor_result));
                xor_result = new_xor_result;
            }
            j = j + 1;
        }
        //@ assert xor_result >= 0;

        if (min > xor_result)
        {
            min = xor_result;
        }
        //@ assert min >= 0;

        i = i + 1;
    }
    return min;
}
