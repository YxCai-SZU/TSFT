#include <stdint.h>

/*@
    requires (0 <= (input) < 12);
    ensures 0 <= \result < 24;
    ensures \result == ((input) == 0 ? 0 :
        (input) == 1 ? 1 :
        (input) == 2 ? 2 :
        (input) == 3 ? 3 :
        (input) == 4 ? 4 :
        (input) == 5 ? 5 :
        (input) == 6 ? 6 :
        (input) == 7 ? 7 :
        (input) == 8 ? 8 :
        (input) == 9 ? 9 :
        (input) == 10 ? 10 :
        11);
*/
int64_t func(int64_t input)
{
    int64_t result;
    result = input;

    if (input == 0) {
        result = 0;
    } else if (input == 1) {
        result = 1;
    } else if (input == 2) {
        result = 2;
    } else if (input == 3) {
        result = 3;
    } else if (input == 4) {
        result = 4;
    } else if (input == 5) {
        result = 5;
    } else if (input == 6) {
        result = 6;
    } else if (input == 7) {
        result = 7;
    } else if (input == 8) {
        result = 8;
    } else if (input == 9) {
        result = 9;
    } else if (input == 10) {
        result = 10;
    } else if (input == 11) {
        result = 11;
    }

    //@ assert 0 <= result < 24;
    return result;
}
