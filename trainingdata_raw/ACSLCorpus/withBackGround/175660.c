#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_numbers(int *arr, integer len) =
        len >= 3 &&
        1 <= arr[0] && arr[0] <= 13 &&
        1 <= arr[1] && arr[1] <= 13 &&
        1 <= arr[2] && arr[2] <= 13;

    predicate is_triangle_sum(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires \valid_read(arr + (0 .. 2));
    requires valid_numbers(arr, len);
    ensures \result == true <==> is_triangle_sum(arr[0], arr[1], arr[2]);
    assigns \nothing;
*/
bool func(int *arr, size_t len) {
    int a;
    int b;
    int c;
    bool result;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert a + b == c || a + c == b || b + c == a <==> is_triangle_sum(a, b, c);

    if (a + b == c || a + c == b || b + c == a) {
        //@ assert is_triangle_sum(a, b, c);
        result = true;
    } else {
        //@ assert !is_triangle_sum(a, b, c);
        result = false;
    }

    return result;
}
