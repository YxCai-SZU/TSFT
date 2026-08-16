#include <stdbool.h>

/*@
    requires (\valid_read((input)) &&
        \valid_read((input) + 1) &&
        \valid_read((input) + 2) &&
        1 <= (input)[0] <= 20 &&
        1 <= (input)[1] <= 20 &&
        1 <= (input)[2] <= 20);
    ensures \result >= 0;
    ensures \result <= ((input[0]) + (input[1]) + (input[2]));
    assigns \nothing;
*/
int func(int *input) {
    int answer = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int original_a = 0;
    int original_b = 0;
    int original_c = 0;

    answer = 0;
    a = input[0];
    b = input[1];
    c = input[2];
    original_a = input[0];
    original_b = input[1];
    original_c = input[2];

    //@ assert a >= 1 && a <= 20;
    //@ assert b >= 1 && b <= 20;
    //@ assert c >= 1 && c <= 20;

    answer += (a < b) ? a : b;
    if (b < a) {
        a = b;
        b = original_b;
    } else {
        b = a;
        a = original_a;
    }

    //@ assert answer >= 0;
    //@ assert answer <= original_a + original_b + original_c;

    answer += (b < c) ? b : c;
    if (c < b) {
        b = c;
        c = original_c;
    } else {
        c = b;
        b = original_b;
    }

    //@ assert answer >= 0;
    //@ assert answer <= original_a + original_b + original_c;

    answer += (a < c) ? a : c;

    //@ assert answer >= 0;
    //@ assert answer <= a + b + c;
    //@ assert answer <= ((original_a) + (original_b) + (original_c));

    return answer;
}
