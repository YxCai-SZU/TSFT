/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - ((a) + (b)));
    ensures \result >= 1 && \result <= 6;
*/
int func(int a, int b)
{
    int result = -1;

    //@ assert (1 <= (a) && (a) <= 3 &&         1 <= (b) && (b) <= 3 &&         (a) != (b));

    if (a == 1) {
        if (b == 2) {
            result = 3;
        } else if (b == 3) {
            result = 2;
        }
    } else if (a == 2) {
        if (b == 1) {
            result = 3;
        } else if (b == 3) {
            result = 1;
        }
    } else if (a == 3) {
        if (b == 1) {
            result = 2;
        } else if (b == 2) {
            result = 1;
        }
    }

    //@ assert result == (6 - ((a) + (b)));
    //@ assert result >= 1 && result <= 6;

    return result;
}
