#include <stdbool.h>

/*@ requires \valid(v + (0..2));
    requires (1 <= (v[0]) && (v[0]) <= 100) && (1 <= (v[1]) && (v[1]) <= 100) && (1 <= (v[2]) && (v[2]) <= 100);
    assigns \nothing;
    ensures \result == 1 <==> ((v[0]) + (v[1]) == (v[2]) || (v[1]) + (v[2]) == (v[0]) || (v[2]) + (v[0]) == (v[1]));
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;
    int x;
    int y;
    int z;
    int min_val;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a + b <= 200;
    x = a + b;
    //@ assert b + c <= 200;
    y = b + c;
    //@ assert c + a <= 200;
    z = c + a;

    if (x < y) {
        if (x < z) {
            min_val = x;
        } else {
            min_val = z;
        }
    } else {
        if (y < z) {
            min_val = y;
        } else {
            min_val = z;
        }
    }

    result = (min_val == a || min_val == b || min_val == c);
    return result;
}
