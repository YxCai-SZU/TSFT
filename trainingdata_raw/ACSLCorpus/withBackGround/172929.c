#include <stdbool.h>

/*@ predicate is_sorted(integer a, integer b, integer c) = a < b && b < c; */

/*@
    requires \valid_read(numbers + (0..2));
    requires numbers[0] >= 1 && numbers[0] <= 100;
    requires numbers[1] >= 1 && numbers[1] <= 100;
    requires numbers[2] >= 1 && numbers[2] <= 100;
    assigns \nothing;
    ensures \result == true <==> (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
*/
bool func(const int numbers[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    if (a < b) {
        if (b < c) {
            //@ assert is_sorted(a, b, c);
            result = true;
        } else {
            //@ assert !is_sorted(a, b, c);
            result = false;
        }
    } else {
        //@ assert !is_sorted(a, b, c);
        result = false;
    }

    return result;
}
