#include <stdbool.h>
#include <stddef.h>

/*@ predicate requires_fn(integer x) = 0 <= x < 128; */
/*@ predicate ensures_fn(integer x, integer result) = result == (x >= 64); */

/*@
  requires requires_fn(x);
  assigns \nothing;
  ensures ensures_fn(x, \result);
*/
bool greater_than_or_equal(unsigned char x) {
    //@ assert requires_fn(x);
    return x >= 64;
}

/*@
  predicate all_ensures_true(unsigned char* v, integer len, integer j) =
    \forall integer i; 0 <= i < j ==> ensures_fn(v[i], 1);
*/

/*@
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> requires_fn(v[i]);
  assigns \nothing;
  ensures \result ==> \forall integer i; 0 <= i < len ==> ensures_fn(v[i], 1);
  ensures !\result ==> \exists integer i; 0 <= i < len && ensures_fn(v[i], 0);
*/
bool greater_than_or_equal_list(unsigned char* v, size_t len) {
    size_t j = 0;
    /*@
      loop invariant 0 <= j <= len;
      loop invariant \forall integer i; 0 <= i < len ==> requires_fn(v[i]);
      loop invariant all_ensures_true(v, len, j);
      loop assigns j;
      loop variant len - j;
    */
    while (j < len) {
        //@ assert requires_fn(v[j]);
        if (!greater_than_or_equal(v[j])) {
            return false;
        }
        //@ assert ensures_fn(v[j], 1);
        j++;
    }
    return true;
}

int main() {
    return 0;
}
