#include <stdbool.h>


bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a >= 1 && a <= 5000;
    //@ assert b >= 1 && b <= 5000;
    //@ assert c >= 1 && c <= 10000;
    result = (a + b >= c);
    //@ assert result == (v[0] + v[1] >= v[2]);
    return result;
}
