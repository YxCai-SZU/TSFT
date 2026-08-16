#include <stdbool.h>

/*@ predicate is_valid_range(integer a0, integer a1, integer a2) =
      a0 >= -100 && a0 <= 100 &&
      a1 >= -100 && a1 <= 100 &&
      a2 >= -100 && a2 <= 100;
*/

/*@ lemma array_length_lemma:
      \forall integer a0, a1, a2;
      is_valid_range(a0, a1, a2) ==>
      (a0 <= a2 && a2 <= a1) == (a0 <= a2 && a2 <= a1);
*/

/*@ requires \valid_read(a + (0..2));
    requires is_valid_range(a[0], a[1], a[2]);
    ensures \result == (a[0] <= a[2] && a[2] <= a[1]);
    assigns \nothing;
*/
bool func(const int a[3]) {
    bool result;
    
    //@ assert a[0] >= -100 && a[0] <= 100;
    //@ assert a[1] >= -100 && a[1] <= 100;
    //@ assert a[2] >= -100 && a[2] <= 100;
    
    result = (a[0] <= a[2] && a[2] <= a[1]);
    
    //@ assert result == (a[0] <= a[2] && a[2] <= a[1]);
    return result;
}
