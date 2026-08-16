#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(size_t N, unsigned int *A) =
      (1 <= N && N <= 100) &&
      \valid(A + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> (1 <= A[i] && A[i] <= 100);
*/

/*@ predicate ans_bounds(size_t i, size_t N, size_t ans) =
      (0 <= i && i <= N) &&
      (0 <= ans && ans <= i);
*/

/*@ lemma ans_non_negative:
      \forall size_t i, N, ans; ans_bounds(i, N, ans) ==> ans >= 0;
*/

/*@ lemma ans_upper_bound:
      \forall size_t i, N, ans; ans_bounds(i, N, ans) ==> ans <= N;
*/

/*@ requires valid_array(N, A);
    ensures \result >= 0;
    ensures \result <= N;
*/
unsigned int func(size_t N, unsigned int *A)
{
    unsigned int ans = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= N;
        loop invariant ans_bounds(i, N, ans);
        loop invariant valid_array(N, A);
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N)
    {
        //@ assert valid_array(N, A);
        
        if ((i + 1) % 2 == 0)
        {
            ans += 0;
        }
        else
        {
            unsigned int x = A[i];
            if (x & 1)
            {
                ans += 1;
            }
        }
        
        i += 1;
        
        //@ assert ans_bounds(i, N, ans);
    }
    
    //@ assert ans_bounds(N, N, ans);
    return ans;
}
