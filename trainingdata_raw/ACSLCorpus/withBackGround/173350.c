#include <stddef.h>

/*@ predicate is_valid_array(int *arr, size_t len, size_t N) =
      len == N &&
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= (int)N &&
      \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@ lemma cnt_bounds:
      \forall integer cnt, index, N;
        cnt >= 1 && cnt <= index + 1 && index + 1 <= N ==> cnt <= N;
*/

/*@ lemma min_bound_bounds:
      \forall integer min_bound, N;
        min_bound >= 1 && min_bound <= (int)N ==> 1 <= min_bound <= (int)N;
*/

/*@
  requires N >= 1 && N <= 200000;
  requires \valid(P + (0 .. N-1));
  requires is_valid_array(P, N, N);
  ensures \result >= 1 && \result <= N;
*/
size_t func(size_t N, int *P)
{
    size_t cnt = 1;
    size_t index = 0;
    int min_bound = P[0];
    
    //@ assert min_bound >= 1 && min_bound <= (int)N;
    
    /*@ loop invariant 0 <= index < N;
        loop invariant cnt >= 1;
        loop invariant cnt <= index + 1;
        loop invariant index + 1 <= N;
        loop invariant is_valid_array(P, N, N);
        loop invariant min_bound >= 1 && min_bound <= (int)N;
        loop assigns cnt, index, min_bound;
        loop variant N - index - 1;
    */
    while (index + 1 < N) {
        index += 1;
        int p = P[index];
        
        //@ assert p >= 1 && p <= (int)N;
        
        if (min_bound >= p) {
            min_bound = p;
            cnt += 1;
        }
        
        //@ assert cnt >= 1;
        //@ assert cnt <= index + 1;
        //@ assert min_bound >= 1 && min_bound <= (int)N;
    }
    
    //@ assert cnt >= 1;
    //@ assert cnt <= N;
    return cnt;
}
