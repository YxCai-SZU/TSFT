#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int* arr, size_t len) =
      len >= 1 && len <= 20 &&
      \forall size_t i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ predicate loop_invariant(int* Hs, size_t N, size_t index, int count, int max) =
      0 <= index <= N &&
      0 <= count <= index &&
      \forall size_t i; 0 <= i < N ==> Hs[i] >= 1 && Hs[i] <= 100;
*/

/*@ lemma count_bounds:
      \forall int* Hs, size_t N, int count;
      valid_array(Hs, N) && 0 <= count <= N ==> 0 <= count <= N;
*/

/*@ requires N >= 1 && N <= 20;
    requires \valid(Hs + (0 .. N-1));
    requires valid_array(Hs, N);
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int func(size_t N, int* Hs) {
    int max;
    int count;
    size_t index;
    
    //@ assert valid_array(Hs, N);
    
    max = 0;
    count = 0;
    index = 0;
    
    /*@ loop invariant loop_invariant(Hs, N, index, count, max);
        loop invariant index <= N;
        loop assigns max, count, index;
        loop variant N - index;
    */
    while (index < N) {
        int H;
        H = Hs[index];
        
        //@ assert H >= 1 && H <= 100;
        
        if (H >= max) {
            //@ assert H >= max;
            count = count + 1;
            max = H;
        }
        
        index = index + 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
