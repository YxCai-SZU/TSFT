#include <stdbool.h>
/*@
    predicate valid_numbers(int* arr, integer len) =
        len == 2 &&
        arr[0] >= 1 && arr[0] <= 100 &&
        arr[1] >= 1 && arr[1] <= 100;

    logic integer compute_result(integer a, integer b) =
        a > b * 2 ? a - b * 2 : 0;

    lemma result_nonnegative:
        \forall integer a, b;
            a >= 1 && a <= 100 && b >= 1 && b <= 100 ==>
            compute_result(a, b) >= 0;
*/

/*@
    requires \valid(numbers + (0..1));
    requires valid_numbers(numbers, 2);
    ensures \result >= 0;
    ensures \result == compute_result(numbers[0], numbers[1]);
    assigns \nothing;
*/
int func(int* numbers) {
    int result;
    result = 0;

    //@ assert numbers[0] >= 1 && numbers[0] <= 100;
    //@ assert numbers[1] >= 1 && numbers[1] <= 100;
    
    if (numbers[0] > numbers[1] * 2) {
        //@ assert numbers[0] > numbers[1] * 2;
        //@ assert numbers[0] - (numbers[1] * 2) >= 0;
        result = numbers[0] - (numbers[1] * 2);
    }

    //@ assert result >= 0;
    //@ assert result == compute_result(numbers[0], numbers[1]);
    return result;
}
