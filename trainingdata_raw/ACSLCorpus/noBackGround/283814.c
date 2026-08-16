#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && b != c) || (a == c && c != b) || (b == c && c != a));
    ensures \result == 3 ==> (a != b && b != c && c != a);
*/
int func(int a, int b, int c)
{
    int count = 0;
    int result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);

    if (a == b) {
        count += 1;
    }
    if (b == c) {
        count += 1;
    }
    if (a == c) {
        count += 1;
    }

    //@ assert count == (((a) == (b) ? 1 : 0) +         ((b) == (c) ? 1 : 0) +         ((a) == (c) ? 1 : 0));
    //@ assert 0 <= count <= 3;

    if (count == 3) {
        result = 1;
        //@ assert result == 1;
    } else if (count == 1 || count == 2) {
        result = 2;
        //@ assert result == 2;
    } else {
        result = 3;
        //@ assert result == 3;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}
