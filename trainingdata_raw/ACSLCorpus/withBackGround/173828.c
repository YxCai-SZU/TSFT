#include <stdbool.h>

/*@ predicate is_valid_range(integer a, integer b, integer c) =
    a <= c && c <= b;
*/

/*@
    requires \valid_read(numbers + (0..2));
    requires -100 <= numbers[0] <= 100;
    requires -100 <= numbers[1] <= 100;
    requires -100 <= numbers[2] <= 100;
    ensures \result == (numbers[0] <= numbers[2] && numbers[2] <= numbers[1]);
*/
bool func(const int numbers[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a == numbers[0];
    //@ assert b == numbers[1];
    //@ assert c == numbers[2];

    if (c >= a && c <= b) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (a <= c && c <= b);
    return result;
}
