#include <stdbool.h>
#include <stdint.h>

/*@ predicate none_case(uint32_t *v, integer len, uint32_t i) =
      \forall integer k; 0 <= k < len ==> v[k] != i;
    predicate some_case(uint32_t *v, integer len, uint32_t i, integer k, int8_t e2, int8_t e) =
      0 <= k < len && v[k] == i && e2 == e;
*/

/*@
    requires \valid(v+(0..len-1));
    requires 0 <= len < 0x80000000;
    ensures \result == -1 ==> none_case(v, len, i);
    ensures \result != -1 ==> some_case(v, len, i, \result, *e2, e);
*/
int32_t func(uint32_t *v, int32_t len, uint32_t i, int8_t e, int8_t *e2) {
    int32_t index = 0;
    int32_t result = -1;
    *e2 = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant result == -1 ==> none_case(v, index, i);
        loop invariant result != -1 ==> some_case(v, len, i, result, *e2, e);
        loop assigns index, result, *e2;
        loop variant len - index;
    */
    while (index < len) {
        if (v[index] == i) {
            result = index;
            *e2 = e;
            break;
        }
        index = index + 1;
    }
    
    return result;
}

/*@ lemma loop_preservation:
      \forall uint32_t *v, integer len, uint32_t i, integer index;
      none_case(v, len, i) && 0 <= index < len && v[index] != i ==>
      none_case(v, index+1, i);
*/

/*@ lemma found_implies_some:
      \forall uint32_t *v, integer len, uint32_t i, integer index, int8_t e;
      0 <= index < len && v[index] == i ==>
      some_case(v, len, i, index, e, e);
*/
