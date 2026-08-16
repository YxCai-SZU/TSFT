#include <stdbool.h>

/*@
    requires \valid(numbers + (0..1));
    requires ((2) == 2 &&
        (numbers)[0] >= 1 && (numbers)[0] <= 100 &&
        (numbers)[1] >= 1 && (numbers)[1] <= 100);
    ensures \result >= 0;
    ensures \result == ((numbers[0]) - ((numbers[1]) * 2)) || \result == 0;
*/
int func(int* numbers) {
    int result;
    int a;
    int b;

    result = 0;
    a = numbers[0];
    b = numbers[1];

    result = a - (b * 2);

    if (result < 0) {
        //@ assert result < 0;
        result = 0;
    } else {
        //@ assert result >= 0;
    }

    //@ assert result >= 0;
    //@ assert result == ((a) - ((b) * 2)) || result == 0;

    return result;
}
