#include <stdint.h>

/*@ predicate condition_holds(integer x) =
      (x / 100) * 5 + (x % 100) / 5 >= 20;
*/

/*@ lemma condition_split:
      \forall integer x; 1 <= x <= 100000 ==>
      (condition_holds(x) || !condition_holds(x));
*/

/*@
  requires 1 <= x <= 100000;
  ensures \result == 1 || \result == 0;
  ensures \result == 1 ==> condition_holds(x);
  ensures \result == 0 ==> !condition_holds(x);
*/
int32_t func(uint32_t x) {
    uint32_t d;
    uint32_t m;
    uint32_t c;
    int32_t result;

    d = x / 100;
    m = x % 100;
    c = d * 5 + m / 5;

    //@ assert c == (x / 100) * 5 + (x % 100) / 5;

    if (c >= 20) {
        //@ assert condition_holds(x);
        result = 1;
    } else {
        //@ assert !condition_holds(x);
        result = 0;
    }

    return result;
}
