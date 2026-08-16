#include <stdbool.h>

/*@
requires \valid_read(numbers + (0 .. 2));
requires ((3) == 3 &&
    \forall integer i; 0 <= i < (3) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
ensures \result == (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
assigns \nothing;
*/
bool func(int *numbers) {
    int a;
    int b;
    int c;
    int ab;
    int bc;
    bool is_equal;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    ab = b - a;
    bc = c - b;

    is_equal = false;
    //@ assert ab == bc ==> is_equal == false;
    if (ab == bc) {
        is_equal = true;
    }

    //@ assert is_equal == (ab == bc);
    return is_equal;
}
