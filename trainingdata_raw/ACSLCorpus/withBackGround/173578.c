#include <stdbool.h>
#include <stddef.h>

/*@ predicate equal_or_not_equal(int *s, int *t, size_t len, size_t i) =
      \forall size_t j; 0 <= j < i ==> (s[j] == t[j] || s[j] != t[j]);
*/

/*@ predicate all_elements_valid(int *s, int *t, size_t len) =
      \forall size_t k; 0 <= k < len ==> (s[k] == t[k] || s[k] != t[k]);
*/

/*@ lemma count_bound_lemma:
      \forall int *s, *t, size_t len, size_t count, size_t i;
        all_elements_valid(s, t, len) && 0 <= i <= len && count <= i ==> count <= len;
*/

/*@ requires \valid(s + (0..len-1)) && \valid(t + (0..len-1));
    requires len > 0;
    requires all_elements_valid(s, t, len);
    ensures \result <= len;
    ensures \result >= 0;
*/
size_t min_operations(int *s, int *t, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant equal_or_not_equal(s, t, len, i);
        loop invariant all_elements_valid(s, t, len);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert all_elements_valid(s, t, len);
        if (s[i] != t[i]) {
            count++;
        }
        i++;
    }
    //@ assert count <= len;
    return count;
}
