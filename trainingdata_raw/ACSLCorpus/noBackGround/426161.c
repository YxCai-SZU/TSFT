#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        (input)[0] >= 1 && (input)[0] <= 5000 &&
        (input)[1] >= 1 && (input)[1] <= 5000 &&
        (input)[2] >= 1 && (input)[2] <= 10000);
    ensures \result == (input[0] <= input[2] && input[2] <= input[0] + input[1]);
    assigns \nothing;
*/
bool func(int *input) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert input[0] >= 1 && input[0] <= 5000;
    //@ assert input[1] >= 1 && input[1] <= 5000;
    //@ assert input[2] >= 1 && input[2] <= 10000;
    
    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert a >= 1 && a <= 5000;
    //@ assert b >= 1 && b <= 5000;
    //@ assert a + b <= 10000;

    result = (a <= c) && (c <= a + b);
    return result;
}
