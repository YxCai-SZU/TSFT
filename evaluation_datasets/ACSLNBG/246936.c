#include <stdbool.h>


bool func(int s[3]) {
    int a, b, c;
    bool result;

    a = s[0];
    b = s[1];
    c = s[2];

    //@ assert a >= 1 && a <= 100;
    result = (a + b == c) || (a + c == b) || (b + c == a);
    return result;
}
