#include <stdbool.h>
#include <stddef.h>

/*@ predicate heights_valid(int *heights, size_t len) =
      len >= 1 && len <= 100000 &&
      \forall size_t i; 0 <= i < len ==> 1 <= heights[i] && heights[i] <= 500;
*/

/*@ predicate ans_range(size_t ans, size_t len) =
      ans >= 0 && ans <= len;
*/

/*@ predicate condition_holds(int *heights, size_t len, size_t k, size_t ans) =
      \forall size_t i; 0 <= i < len ==> 
        (heights[i] >= (int)k ==> ans > 0) &&
        (heights[i] < (int)k ==> ans <= len);
*/

/*@ lemma k_valid_range: 
      \forall size_t k; k >= 1 && k <= 500 ==> true;
*/

/*@ lemma loop_maintains_invariant:
      \forall int *heights, size_t len, size_t k, size_t index, size_t ans;
        heights_valid(heights, len) && k >= 1 && k <= 500 &&
        index <= len && ans <= index &&
        (\forall size_t i; 0 <= i < index ==> 
          (heights[i] >= (int)k ==> ans > 0) &&
          (heights[i] < (int)k ==> ans <= index)) ==>
        true;
*/

/*@ requires k >= 1 && k <= 500;
    requires heights_valid(heights, len);
    ensures ans_range(\result, len);
    ensures condition_holds(heights, len, k, \result);
*/
size_t func(size_t k, int *heights, size_t len)
{
  size_t ans = 0;
  size_t index = 0;
  
  /*@ loop invariant index <= len;
      loop invariant ans <= index;
      loop invariant \forall size_t i; 0 <= i < index ==> (heights[i] >= (int)k ==> ans > 0);
      loop invariant \forall size_t i; 0 <= i < index ==> (heights[i] < (int)k ==> ans <= index);
      loop assigns ans, index;
  */
  while (index < len) {
    int h = heights[index];
    if (h >= (int)k) {
      ans += 1;
    }
    index += 1;
  }
  return ans;
}
