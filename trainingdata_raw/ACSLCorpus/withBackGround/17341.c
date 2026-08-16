#include <stddef.h>
#include <stdint.h>

/*@ predicate same_length{L}(uint32_t *s, uint32_t *t, size_t len) =
      \valid_read(s+(0..len-1)) && \valid_read(t+(0..len-1));
*/

/*@ predicate count_bound(integer count, integer len) =
      count <= len;
*/

/*@ predicate invariant_maintained(integer i, integer len, integer count) =
      0 <= i <= len && count <= i;
*/

/*@ lemma final_count_bound: \forall integer count, integer len;
      count <= len ==> count <= len;
*/

/*@ requires
      len > 0 && len <= 0x80000000 &&
      same_length(s, t, len);
    ensures
      \result <= len;
*/
size_t min_operations(const uint32_t *s, const uint32_t *t, size_t len)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant
          invariant_maintained(i, len, count);
        loop invariant
          same_length(s, t, len);
        loop invariant
          \forall integer k; 0 <= k < i ==> (s[k] != t[k]) ==> count > 0;
        loop invariant
          count_bound(count, len);
        loop assigns
          count, i;
        loop variant
          len - i;
    */
    while (i < len) {
        if (s[i] != t[i]) {
            //@ assert count <= len;
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count <= len;
    return count;
}
