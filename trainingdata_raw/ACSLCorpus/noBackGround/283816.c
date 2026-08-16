#include <stddef.h>
#include <stdint.h>

/*@
    requires 2 <= N && N <= 100;
    requires \valid(B+(0..N-2));
    requires ((2 <= (N) && (N) <= 100) &&
    (\forall integer j; 0 <= j < (N)-1 ==> 0 <= (B)[j] && (B)[j] <= 100000));
    ensures \result >= 0;
*/
int64_t func(size_t N, int64_t *B)
{
    int64_t ans = 0;
    size_t i = 0;
    
    //@ assert ans >= 0;
    ans = B[0];
    //@ assert ans >= 0;
    
    /*@ loop invariant 0 <= i <= N-2;
        loop invariant ans >= 0;
        loop invariant ans <= (((i)+1) * 100000);
        loop assigns ans, i;
        loop variant N-2-i;
    */
    while (i < N - 2) {
        int64_t min_value = 0;
        
        if (B[i] < B[i + 1]) {
            min_value = B[i];
        } else {
            min_value = B[i + 1];
        }
        
        //@ assert min_value >= 0 && min_value <= 100000;
        ans += min_value;
        //@ assert ans >= 0;
        i += 1;
        //@ assert ans <= (((i)+1) * 100000);
    }
    
    //@ assert i == N-2;
    ans += B[N - 2];
    //@ assert ans >= 0;
    
    return ans;
}
