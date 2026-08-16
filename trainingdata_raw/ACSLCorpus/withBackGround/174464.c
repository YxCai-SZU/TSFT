#include <stdbool.h>

/*@ predicate is_triangle_sum(integer a, integer b, integer c) =
    a + b == c || b + c == a || c + a == b;
*/

/*@
    requires \valid_read(input + (0..2));
    requires 1 <= input[0] && input[0] <= 100;
    requires 1 <= input[1] && input[1] <= 100;
    requires 1 <= input[2] && input[2] <= 100;
    ensures \result == true <==> is_triangle_sum(input[0], input[1], input[2]);
*/
bool func(const unsigned int input[3]) {
    bool result = false;

    if (input[0] + input[1] == input[2]) {
        result = true;
    } else if (input[1] + input[2] == input[0]) {
        result = true;
    } else if (input[2] + input[0] == input[1]) {
        result = true;
    }

    //@ assert result == true <==> is_triangle_sum(input[0], input[1], input[2]);

    return result;
}
