#include <stdbool.h>

/*@
    predicate is_valid_range(integer i, integer len) =
        0 <= i && i < len;

    predicate element_in_range(int *arr, integer i) =
        1 <= arr[i] && arr[i] <= 100;

    predicate sum_condition(int a, int b, int c) =
        a + b == c || a + c == b || b + c == a;

    logic integer vector_at(int *arr, integer i) = arr[i];

    lemma sum_bounds:
        \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 100 ==> a + b <= 200;
*/

/*@
    requires \valid(numbers + (0..2));
    requires numbers[0] >= 1 && numbers[0] <= 100;
    requires numbers[1] >= 1 && numbers[1] <= 100;
    requires numbers[2] >= 1 && numbers[2] <= 100;
    ensures \result == true <==> 
        (numbers[0] + numbers[1] == numbers[2] || 
         numbers[1] + numbers[2] == numbers[0] || 
         numbers[2] + numbers[0] == numbers[1]);
*/
bool func(int *numbers) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;
    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;

    if (a + b == c || a + c == b || b + c == a) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
