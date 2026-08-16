#include <stdbool.h>

/*@
    predicate valid_numbers(int *numbers) =
        \valid(numbers) &&
        numbers[0] >= 1 && numbers[0] <= 13 &&
        numbers[1] >= 1 && numbers[1] <= 13 &&
        numbers[2] >= 1 && numbers[2] <= 13;

    logic integer diff1(integer a, integer b) = b - a;
    logic integer diff2(integer b, integer c) = c - b;
    predicate same_difference(integer a, integer b, integer c) = 
        diff1(a, b) == diff2(b, c);
*/

/*@
    requires valid_numbers(numbers);
    ensures \result == 1 <==> same_difference(numbers[0], numbers[1], numbers[2]);
    assigns \nothing;
*/
bool func(int *numbers) {
    bool answer;
    bool is_same_difference;
    int a;
    int b;
    int c;
    int diff1;
    int diff2;

    answer = false;
    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    is_same_difference = false;
    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 == (b - a);
    if (diff1 == diff2) {
        is_same_difference = true;
    }

    if (is_same_difference) {
        answer = true;
    } else {
        answer = false;
    }

    //@ assert answer == 1 <==> same_difference(a, b, c);
    return answer;
}
