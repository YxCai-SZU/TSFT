#include <limits.h>

/*@
    requires (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000) && (-1000 <= (C) <= 1000) && (-1000 <= (D) <= 1000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
*/
int func(int A, int B, int C, int D)
{
    int x;
    int y;
    int result;

    //@ assert (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000);
    //@ assert -1000000 <= ((A) * (B)) <= 1000000;
    x = A * B;

    //@ assert (-1000 <= (C) <= 1000) && (-1000 <= (D) <= 1000);
    //@ assert -1000000 <= ((C) * (D)) <= 1000000;
    y = C * D;

    //@ assert x >= ((A) * (B));
    //@ assert y >= ((C) * (D));

    if (x > y) {
        result = x;
    } else {
        result = y;
    }

    //@ assert result == ((A) * (B)) || result == ((C) * (D));
    //@ assert result >= ((A) * (B));
    //@ assert result >= ((C) * (D));
    return result;
}
