#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, size_t N) =
      N > 0 && N <= 100 &&
      \forall size_t i; 0 <= i < N ==> 1 <= a[i] <= 100;
*/

/*@ predicate count_invariant(int *a, size_t N, size_t index, int count) =
      0 <= index <= N &&
      0 <= count <= (int)index &&
      \forall size_t j; 0 <= j < index ==> (a[j] == 2 ==> count > 0);
*/

/*@ lemma count_bound: \forall int *a, size_t N, size_t index, int count;
      valid_array(a, N) && count_invariant(a, N, index, count) ==> 0 <= count <= (int)N;
*/

/*@ requires valid_array(a, N);
    assigns \nothing;
    ensures 0 <= \result <= (int)N;
*/
int func(size_t N, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant count_invariant(a, N, index, count);
        loop assigns count, index;
        loop variant N - index;
    */
    while (index < N) {
        //@ assert 0 <= index < N;
        if (a[index] == 2) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
