#include <stdint.h>

/*@
    requires (2 <= (N) && (N) <= 1000000000000000000 &&
        1 <= (A) && (A) < (B) && (B) <= (N));
    ensures \result == (((A) + (B)) % 2 == 0 ?
            ((B) - (A)) / 2 :
            (((A) - 1) < ((N) - (B)) ? ((A) - 1) : ((N) - (B))) + ((B) - (A) - 1) / 2);
    ensures 0 <= \result && \result <= N;
*/
uint64_t func(uint64_t N, uint64_t A, uint64_t B)
{
    uint64_t result;
    uint64_t left;
    uint64_t right;
    uint64_t min_val;

    //@ assert (2 <= (N) && (N) <= 1000000000000000000 &&         1 <= (A) && (A) < (B) && (B) <= (N));
    
    if ((A + B) % 2 == 0)
    {
        result = (B - A) / 2;
        //@ assert result == (B - A) / 2;
    }
    else
    {
        left = A - 1;
        right = N - B;
        
        //@ assert left == A - 1;
        //@ assert right == N - B;
        
        if (left < right)
        {
            min_val = left;
        }
        else
        {
            min_val = right;
        }
        
        //@ assert min_val == (left < right ? left : right);
        //@ assert min_val >= 0;
        //@ assert min_val <= N;
        //@ assert (B - A - 1) / 2 >= 0;
        //@ assert (B - A - 1) / 2 <= N;
        //@ assert min_val + (B - A - 1) / 2 <= N;
        
        result = min_val + (B - A - 1) / 2;
    }
    
    //@ assert result == (((A) + (B)) % 2 == 0 ?             ((B) - (A)) / 2 :             (((A) - 1) < ((N) - (B)) ? ((A) - 1) : ((N) - (B))) + ((B) - (A) - 1) / 2);
    //@ assert 0 <= result && result <= N;
    return result;
}
