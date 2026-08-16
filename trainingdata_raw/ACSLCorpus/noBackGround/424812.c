#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == ((numbers[0] < numbers[1] && numbers[1] < numbers[2]) || 
                       (numbers[0] > numbers[1] && numbers[1] > numbers[2]));
*/
bool func(const int* numbers, size_t len) {
    int a;
    int b;
    int c;
    bool increasing;
    bool decreasing;
    bool result;

    if (len < 3) {
        return false;
    }

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    increasing = a < b && b < c;
    decreasing = a > b && b > c;
    result = increasing || decreasing;

    //@ assert result == ((a < b && b < c) || (a > b && b > c));

    return result;
}
