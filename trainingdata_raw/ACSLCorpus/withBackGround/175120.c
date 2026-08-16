#include <stdbool.h>

/*@ predicate a_eq_b(integer a, integer b) = a == b; */
/*@ predicate b_eq_c(integer b, integer c) = b == c; */
/*@ predicate a_eq_c(integer a, integer c) = a == c; */

/*@ lemma case_1:
      \forall integer a,b,c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        a_eq_b(a,b) && !b_eq_c(b,c) ==> a == b && b != c;
*/

/*@ lemma case_2:
      \forall integer a,b,c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        !a_eq_b(a,b) && b_eq_c(b,c) ==> a != b && b == c;
*/

/*@ lemma case_3:
      \forall integer a,b,c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        a_eq_c(a,c) && !a_eq_b(a,b) ==> a == c && a != b;
*/

/*@ lemma case_4:
      \forall integer a,b,c;
        -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 &&
        !a_eq_b(a,b) && !b_eq_c(b,c) && !a_eq_c(a,c) ==> 
        a != b && b != c && a != c;
*/

/*@
  requires -100 <= a <= 100;
  requires -100 <= b <= 100;
  requires -100 <= c <= 100;
  ensures (a == b && b != c) ==> \result == c;
  ensures (a != b && b == c) ==> \result == a;
  ensures (a == c && a != b) ==> \result == b;
  ensures (a != b && b != c && a != c) ==> \result == 0;
  ensures -100 <= \result <= 100;
*/
int func(int a, int b, int c) {
    int result;
    
    if (a == b) {
        //@ assert a_eq_b(a,b);
        //@ assert !b_eq_c(b,c) ==> (a == b && b != c);
        result = c;
    } else if (a == c) {
        //@ assert a_eq_c(a,c);
        //@ assert !a_eq_b(a,b) ==> (a == c && a != b);
        result = b;
    } else if (b == c) {
        //@ assert b_eq_c(b,c);
        //@ assert !a_eq_b(a,b) ==> (a != b && b == c);
        result = a;
    } else {
        //@ assert !a_eq_b(a,b) && !b_eq_c(b,c) && !a_eq_c(a,c);
        //@ assert a != b && b != c && a != c;
        result = 0;
    }
    
    //@ assert -100 <= result <= 100;
    return result;
}
