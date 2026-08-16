#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a) * 10 + (b) + (c)) || \result == ((a) + (b) * 10 + (c)) || \result == ((a) + (b) + (c) * 10);
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    int result = INT_MIN;
    int result1;
    int result2;
    int result3;

    result1 = a * 10 + b + c;
    result2 = a + b * 10 + c;
    result3 = a + b + c * 10;

    //@ assert result1 == ((a) * 10 + (b) + (c));
    //@ assert result2 == ((a) + (b) * 10 + (c));
    //@ assert result3 == ((a) + (b) + (c) * 10);

    if (result1 > result) {
        result = result1;
    }
    if (result2 > result) {
        result = result2;
    }
    if (result3 > result) {
        result = result3;
    }

    //@ assert result == result1 || result == result2 || result == result3;
    //@ assert result >= 11;

    return result;
}
