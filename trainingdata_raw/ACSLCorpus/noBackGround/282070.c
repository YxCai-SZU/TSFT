#include <stdbool.h>
/*@
    requires \valid_read(input + (0..2));
    requires ((3) == 3 &&
        1 <= (input)[0] <= 100 &&
        1 <= (input)[1] <= 20 &&
        1 <= (input)[2] <= 2000);
    ensures \result >= 0;
    ensures \result <= input[2];
    assigns \nothing;
*/
int func(int* input) {
    int A;
    int B;
    int C;
    int train;
    int result;

    A = input[0];
    B = input[1];
    C = input[2];

    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 20;
    //@ assert 1 <= C <= 2000;

    //@ assert ((A) * (B)) <= 2000;
    //@ assert ((A) * (B)) >= 1;

    train = A * B;

    if (train < C) {
        result = train;
    } else {
        result = C;
    }

    //@ assert result >= 0;
    //@ assert result <= C;

    return result;
}
