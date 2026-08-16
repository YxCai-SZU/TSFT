#include <stdbool.h>

/*@ predicate is_range_sorted(integer a, integer b, integer c) =
    a < b && b < c;
*/

/*@
    requires \valid_read(numbers + (0..2));
    requires -100 <= numbers[0] <= 100;
    requires -100 <= numbers[1] <= 100;
    requires -100 <= numbers[2] <= 100;
    ensures \result == 1 <==> is_range_sorted(numbers[0], numbers[1], numbers[2]);
*/
bool is_range_sorted_c(int numbers[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;
    //@ assert -100 <= c <= 100;

    result = a < b && b < c;
    return result;
}
