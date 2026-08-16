#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires ((len) >= 3 &&
        \forall integer i; 0 <= i < 3 ==> 1 <= (numbers)[i] <= 13);
    ensures \result == 1 <==> ((numbers[0]) + (numbers[1]) == (numbers[2]) || (numbers[1]) + (numbers[2]) == (numbers[0]) || (numbers[2]) + (numbers[0]) == (numbers[1]));
*/
bool func(int *numbers, int len) {
    int a;
    int b;
    int c;
    bool is_possible;
    int temp;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    is_possible = false;

    // Check if a + b = c
    temp = a + b;
    //@ assert temp == a + b;
    if (temp == c) {
        is_possible = true;
    }

    // Check if b + c = a
    temp = b + c;
    //@ assert temp == b + c;
    if (temp == a) {
        is_possible = true;
    }

    // Check if c + a = b
    temp = c + a;
    //@ assert temp == c + a;
    if (temp == b) {
        is_possible = true;
    }

    //@ assert is_possible == 1 <==> ((a) + (b) == (c) || (b) + (c) == (a) || (c) + (a) == (b));
    return is_possible;
}
