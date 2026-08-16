#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_positive(integer x) = x > 0; */
/*@ predicate valid_index(integer i, integer n) = 0 <= i < n; */
/*@ predicate array_all_positive(unsigned int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> is_positive(arr[i]); */

/*@ lemma result_bounds: 
      \forall integer n, integer idx, integer res; 
      is_positive(n) && 1 <= idx <= n && 1 <= res <= idx ==> 1 <= res <= n; */

/*@ requires N > 0;
    requires \valid(Hs + (0 .. N-1));
    requires array_all_positive(Hs, N);
    assigns \nothing;
    ensures 1 <= \result <= N;
*/
unsigned int func(unsigned int N, unsigned int *Hs) {
    unsigned int max_value;
    unsigned int result;
    size_t index;
    
    max_value = Hs[0];
    result = 1;
    index = 1;
    
    /*@ loop invariant 1 <= index <= N;
        loop invariant 1 <= result <= index;
        loop invariant array_all_positive(Hs, N);
        loop assigns max_value, result, index;
        loop variant N - index;
    */
    while (index < N) {
        unsigned int H = Hs[index];
        
        //@ assert is_positive(H);
        if (max_value <= H) {
            max_value = H;
            result += 1;
        }
        //@ assert 1 <= result <= index + 1;
        index += 1;
    }
    
    //@ assert 1 <= result <= N;
    return result;
}
