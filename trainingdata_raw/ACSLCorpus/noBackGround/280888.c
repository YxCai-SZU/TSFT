#include <stdbool.h>

/*@ requires \valid_read(numbers + (0..2));
    requires numbers[0] >= 1 && numbers[0] <= 13;
    requires numbers[1] >= 1 && numbers[1] <= 13;
    requires numbers[2] >= 1 && numbers[2] <= 13;
    ensures \result == 1 <==> ((numbers[0]) + (numbers[1]) > (numbers[2]) && (numbers[0]) + (numbers[2]) > (numbers[1]) && (numbers[1]) + (numbers[2]) > (numbers[0]));
*/
bool func(const int numbers[3]) {
    bool result = true;

    //@ assert numbers[0] >= 1 && numbers[0] <= 13;
    //@ assert numbers[1] >= 1 && numbers[1] <= 13;
    //@ assert numbers[2] >= 1 && numbers[2] <= 13;

    if (numbers[1] + numbers[2] <= numbers[0] ||
        numbers[0] + numbers[2] <= numbers[1] ||
        numbers[0] + numbers[1] <= numbers[2]) {
        result = false;
    }

    //@ assert result == 1 <==> ((numbers[0]) + (numbers[1]) > (numbers[2]) && (numbers[0]) + (numbers[2]) > (numbers[1]) && (numbers[1]) + (numbers[2]) > (numbers[0]));
    return result;
}
