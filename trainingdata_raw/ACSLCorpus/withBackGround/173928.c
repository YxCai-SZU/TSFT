#include <stdbool.h>

/*@ predicate is_sorted(int *a, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> a[i] <= a[j];
*/

/*@ predicate has_at_least_one_common_element(int *a, integer len_a, int *b, integer len_b) =
      \exists integer i, j; 0 <= i < len_a && 0 <= j < len_b && a[i] == b[j];
*/

/*@ lemma assertion_lemma:
      \forall int *a, integer len_a, int *b, integer len_b;
      is_sorted(a, len_a) && is_sorted(b, len_b) && 
      has_at_least_one_common_element(a, len_a, b, len_b) ==>
      \exists integer i, j; 0 <= i < len_a && 0 <= j < len_b && a[i] == b[j];
*/

/*@ lemma assertion2_lemma:
      \forall int *a, integer len_a;
      is_sorted(a, len_a) ==>
      \forall integer i, j; 0 <= i < j < len_a ==> a[i] <= a[j];
*/

int main() {
    return 0;
}
