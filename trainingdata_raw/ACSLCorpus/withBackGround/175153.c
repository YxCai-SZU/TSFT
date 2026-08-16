#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) =
        1 <= x && x <= 100000;

    logic integer mod_100(integer x) = x % 100;

    lemma mod_preservation:
        \forall integer x, temp;
            is_valid_range(x) && 0 <= temp <= x && temp % 100 == x % 100 && temp >= 100 ==>
            (temp - 100) % 100 == x % 100;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x >= 2000 || (x >= 105 && mod_100(x) <= 5));
    assigns \nothing;
*/
bool func(unsigned int x) {
    bool result = false;
    unsigned int temp = 0;

    if (x >= 2000) {
        //@ assert x >= 2000;
        result = true;
    } else if (x >= 105) {
        temp = x;
        /*@
            loop invariant 1 <= x <= 100000;
            loop invariant 0 <= temp <= x;
            loop invariant temp % 100 == x % 100;
            loop invariant temp == x % 100 || temp >= 100;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 100) {
            //@ assert temp >= 100;
            temp -= 100;
        }
        if (temp <= 5) {
            //@ assert temp <= 5;
            result = true;
        }
    }
    //@ assert result == (x >= 2000 || (x >= 105 && x % 100 <= 5));
    return result;
}
