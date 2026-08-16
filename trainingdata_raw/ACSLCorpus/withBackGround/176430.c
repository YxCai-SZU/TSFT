#include <stdint.h>
#include <stddef.h>

/*@ predicate arr_pos(size_t len, uint64_t *arr) =
      \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@ lemma answer_bounds:
      \forall integer i; 0 <= i ==> (uint64_t)i >= 0 && (uint64_t)i <= (uint64_t)i;
*/

/*@ requires n > 0 && k > 0 && n <= k;
    requires \valid(arr + (0 .. k-1));
    requires arr_pos(k, arr);
    assigns \nothing;
    ensures 0 <= \result <= k;
*/
uint64_t func(size_t n, size_t k, uint64_t *arr) {
    uint64_t answer = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= k;
        loop invariant answer >= 0;
        loop invariant answer <= index;
        loop invariant arr_pos(k, arr);
        loop assigns answer, index;
        loop variant k - index;
    */
    while (index < k) {
        uint64_t a = arr[index];
        //@ assert a > 0;
        if (a < (uint64_t)(index + 1)) {
            answer += 1;
            //@ assert answer <= index + 1;
        }
        index += 1;
    }
    return answer;
}
