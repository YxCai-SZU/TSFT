#include <stdint.h>

/*@ predicate condition_holds(integer A, integer B) =
      A > B * 2 || B > A * 2;
*/

/*@ predicate condition_fails(integer A, integer B) =
      A <= B * 2 && B <= A * 2;
*/

/*@ lemma condition_split: 
      \forall integer A, B; 
      condition_holds(A, B) || condition_fails(A, B);
*/

/*@
  requires 0 <= A <= 100;
  requires 0 <= B <= 100;
  assigns \nothing;
  ensures condition_holds(A, B) ==> \result == 0;
  ensures condition_fails(A, B) ==> \result == A + B;
*/
int64_t func(int64_t A, int64_t B) {
    int64_t result;
    
    if (A > B * 2 || B > A * 2) {
        //@ assert condition_holds(A, B);
        result = 0;
    } else {
        //@ assert condition_fails(A, B);
        result = A + B;
    }
    
    return result;
}
