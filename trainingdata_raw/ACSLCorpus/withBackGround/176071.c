#include <stdbool.h>

/*@
    predicate has_nine(integer a) =
        a % 10 == 9 || (a / 10) % 10 == 9;
*/

/*@
    requires 10 <= a <= 99;
    ensures \result == true <==> has_nine(a);
    assigns \nothing;
*/
bool func(unsigned long long a) {
    unsigned long long a_tens;
    unsigned long long a_ones;
    bool result;

    a_tens = a;
    a_ones = a;

    // Extract the tens digit
    a_tens = a_tens / 10;
    a_tens = a_tens % 10;

    // Extract the ones digit
    a_ones = a_ones % 10;

    //@ assert a_tens == (a / 10) % 10;
    //@ assert a_ones == a % 10;

    if (a_tens == 9 || a_ones == 9) {
        result = true;
    } else {
        //@ assert a_tens != 9 && a_ones != 9;
        result = false;
    }

    return result;
}
