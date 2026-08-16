#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_positive(integer x) = x > 0; */

/*@ lemma even_positive: \forall integer x; x % 2 == 0 && is_positive(x) ==> \true; */

/*@
  requires \valid(v+(0..len-1));
  requires \forall integer i; 0 <= i < len ==> is_positive(v[i]);
  ensures \forall integer i; 0 <= i < len ==> v[i] > -1;
*/
void establish_forall(int *v, size_t len) {
    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i ==> v[j] > -1;
      loop assigns i;
    */
    for (size_t i = 0; i < len; ++i) {
        //@ assert is_positive(v[i]);
    }
}

int main() {
    return 0;
}
