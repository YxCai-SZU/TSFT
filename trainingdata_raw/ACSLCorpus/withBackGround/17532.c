#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_range(size_t N) = 1 <= N && N <= 100000; */

/*@ predicate is_valid_element(integer val) = 1 <= val && val <= 1000000000; */

/*@ predicate is_valid_array(int *arr, size_t N) =
      \forall integer i; 0 <= i < N ==> is_valid_element(arr[i]); */

/*@ lemma answer_bounds:
      \forall integer answer, integer sunuke_index;
      0 <= answer && answer <= sunuke_index && 0 <= sunuke_index ==> answer >= 0; */

/*@
  requires is_valid_range(N);
  requires \valid_read(input_vec + (0 .. N-1));
  requires is_valid_array(input_vec, N);
  assigns \nothing;
  ensures 0 <= \result && \result <= N;
*/
int func(size_t N, const int *input_vec) {
    int answer = 0;
    size_t sunuke_index = 0;
    int height = 0;

    /*@
      loop invariant 0 <= sunuke_index <= N;
      loop invariant 0 <= answer <= sunuke_index;
      loop invariant is_valid_range(N);
      loop invariant is_valid_array(input_vec, N);
      loop assigns answer, sunuke_index, height;
      loop variant N - sunuke_index;
    */
    while (sunuke_index < N) {
        int h = input_vec[sunuke_index];
        //@ assert is_valid_element(h);
        if (height <= h) {
            answer += 1;
            height = h;
        }
        sunuke_index += 1;
    }
    //@ assert 0 <= answer && answer <= N;
    return answer;
}
