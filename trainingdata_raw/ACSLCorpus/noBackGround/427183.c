#include <stdint.h>

/*@
    requires \valid_read(input + (0..2));
    requires ((3) == 3 &&
        1 <= (input)[0] && (input)[0] <= 20 &&
        1 <= (input)[1] && (input)[1] <= 20 &&
        1 <= (input)[2] && (input)[2] <= 20);
    ensures \result == ((input[2]) * (input[1]) - (input[0]));
*/
int64_t func(int64_t* input)
{
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t bc;
    int64_t result;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= c && c <= 20;
    //@ assert 1 <= b * c <= 400;

    bc = b * c;
    result = bc - a;
    return result;
}
