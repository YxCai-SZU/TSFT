#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((N) >= 1 && (N) <= 200000 &&
        \valid((A) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= 1000000);
    assigns \nothing;
    ensures 0 <= \result <= ((N) * 1000000);
*/
int64_t func(uint64_t N, int64_t *A)
{
    int64_t ans = 0;
    int64_t max = 0;
    uint64_t index = 0;

    /*@
        loop invariant 0 <= index <= N;
        loop invariant 0 <= ans <= ((index) * 1000000);
        loop invariant 0 <= max <= 1000000;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= A[i] <= 1000000;
        loop invariant ((N) >= 1 && (N) <= 200000 &&
        \valid((A) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= 1000000);
        loop assigns ans, max, index;
        loop variant N - index;
    */
    while (index < N)
    {
        int64_t a = A[index];
        
        //@ assert 1 <= a <= 1000000;
        
        if (max > a)
        {
            //@ assert max - a >= 0;
            ans += max - a;
            //@ assert ans <= ((index + 1) * 1000000);
        }
        else
        {
            max = a;
            //@ assert max <= 1000000;
        }
        
        index++;
    }
    
    //@ assert ans <= ((N) * 1000000);
    return ans;
}
