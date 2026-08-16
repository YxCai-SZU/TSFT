#include <stdbool.h>
#include <stddef.h>

/*@ predicate parity(integer x) = x % 2 == 0; */

/*@ lemma test_parity: parity(4) && !parity(7); */

/*@
  requires \valid(list + (0..len-1));
  requires len < 0x80000000;
  assigns \nothing;
  ensures 0 <= \result <= len;
  ensures \forall integer i; 0 <= i < len ==> (list[i] % 2 == 0) ==> list[i] % 2 == 0;
*/
int count_even(const int* list, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer j; 0 <= j < i ==> (list[j] % 2 == 0) ==> list[j] % 2 == 0;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((list[i] & 1) == 0) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
