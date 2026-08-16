#include <stdbool.h>

/*@
    predicate has_seven(integer a) =
        (a / 100 == 7) || ((a / 10) % 10 == 7) || (a % 10 == 7);
*/

/*@
    requires 100 <= a <= 999;
    ensures \result == true <==> has_seven(a);
    assigns \nothing;
*/
bool func(int a)
{
    bool ok = false;
    int temp = a;
    int first_digit;
    int second_digit;
    int third_digit;

    first_digit = temp / 100;
    //@ assert first_digit == a / 100;
    if (first_digit == 7) {
        ok = true;
    }

    temp = a % 100;
    second_digit = temp / 10;
    //@ assert second_digit == (a / 10) % 10;
    if (second_digit == 7) {
        ok = true;
    }

    third_digit = a % 10;
    //@ assert third_digit == a % 10;
    if (third_digit == 7) {
        ok = true;
    }

    //@ assert ok == (first_digit == 7 || second_digit == 7 || third_digit == 7);
    return ok;
}
