#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_range(integer N) = 1 <= N && N <= 100; */
/*@ predicate valid_number(integer x) = 1 <= x && x <= 1000; */
/*@ predicate valid_array(integer N, uint32_t *arr, integer len) = 
      valid_range(N) && len == N && 
      \forall integer i; 0 <= i < len ==> valid_number(arr[i]); */

/*@ logic integer min_value(integer a, integer b) = a < b ? a : b; */

/*@ lemma ans_bounds: 
      \forall integer index, integer ans; 
      0 <= ans <= index ==> ans <= index; */

/*@ requires valid_range(N);
    requires valid_array(N, numbers, N);
    requires \valid(numbers + (0 .. N-1));
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t numbers[]) {
    uint32_t min = 1000000;
    uint32_t ans = 0;
    uint32_t index = 0;
    
    /*@ loop invariant 0 <= index <= N;
        loop invariant 0 <= ans <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> valid_number(numbers[i]);
        loop invariant \forall integer k; 0 <= k < N ==> valid_number(numbers[k]);
        loop invariant valid_range(N);
        loop invariant ans <= N;
        loop assigns min, ans, index;
        loop variant N - index;
    */
    while (index < N) {
        uint32_t n = numbers[index];
        //@ assert valid_number(n);
        if (min <= n) {
            ans += 1;
            min = n;
        }
        index += 1;
    }
    return ans;
}
