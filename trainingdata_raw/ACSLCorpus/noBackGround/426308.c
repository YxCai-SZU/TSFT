#include <stdbool.h>

/*@
    requires \valid_read(input + (0..2));
    requires (-100 <= (input[0]) && (input[0]) <= 100) && (-100 <= (input[1]) && (input[1]) <= 100) && (-100 <= (input[2]) && (input[2]) <= 100);
    ensures \result == (input[0] <= input[2] && input[2] <= input[1]);
*/
bool func(const long long *input) {
    long long a;
    long long b;
    long long c;
    bool result;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert a == input[0];
    //@ assert b == input[1];
    //@ assert c == input[2];

    result = (a <= c && c <= b);
    return result;
}
