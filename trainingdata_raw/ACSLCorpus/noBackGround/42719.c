#include <stdbool.h>

/*@
    requires (\valid((v) + (0..5)) &&
        0 <= (v)[0] <= 123 &&
        0 <= (v)[1] <= 123 &&
        0 <= (v)[2] <= 123 &&
        0 <= (v)[3] <= 123 &&
        0 <= (v)[4] <= 123 &&
        0 <= (v)[5] <= 123);
    ensures \result == 1 <==> ((v[4]) >= (v[0]) && (v[5]) >= (v[1]) && (((v[0])) + ((v[1])) + ((v[2])) + ((v[3]))) <= (v[4]) + (v[5]));
    assigns \nothing;
*/
bool func(int *v)
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    bool result;

    //@ assert (\valid((v) + (0..5)) &&         0 <= (v)[0] <= 123 &&         0 <= (v)[1] <= 123 &&         0 <= (v)[2] <= 123 &&         0 <= (v)[3] <= 123 &&         0 <= (v)[4] <= 123 &&         0 <= (v)[5] <= 123);

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    e = v[4];
    f = v[5];

    result = e >= a && f >= b && a + b + c + d <= e + f;
    //@ assert result == 1 <==> ((e) >= (a) && (f) >= (b) && (((a)) + ((b)) + ((c)) + ((d))) <= (e) + (f));
    return result;
}
