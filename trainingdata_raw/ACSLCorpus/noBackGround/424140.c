#include <stdbool.h>

/*@ requires \valid(numbers + (0..2));
    requires numbers[0] >= 1 && numbers[0] <= 13;
    requires numbers[1] >= 1 && numbers[1] <= 13;
    requires numbers[2] >= 1 && numbers[2] <= 13;
    ensures \result == (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
    assigns \nothing;
*/
bool func(const int numbers[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert numbers[1] - numbers[0] == b - a;
    //@ assert numbers[2] - numbers[1] == c - b;

    result = (b - a == c - b);
    return result;
}
