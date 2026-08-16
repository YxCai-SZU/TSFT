#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000 && -1000 <= (b) <= 1000);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int add;
    int sub;
    int mul;
    int result;

    //@ assert (-1000 <= (a) <= 1000 && -1000 <= (b) <= 1000);
    add = a + b;
    sub = a - b;

    //@ assert (-1000 <= (a) <= 1000 && -1000 <= (b) <= 1000);
    mul = a * b;

    //@ assert mul_bounds: mul >= -1000000 && mul <= 1000000;

    if (add > sub && add > mul) {
        result = add;
    } else if (sub > mul) {
        result = sub;
    } else {
        result = mul;
    }

    //@ assert result == add || result == sub || result == mul;
    //@ assert result >= add;
    //@ assert result >= sub;
    //@ assert result >= mul;

    return result;
}
