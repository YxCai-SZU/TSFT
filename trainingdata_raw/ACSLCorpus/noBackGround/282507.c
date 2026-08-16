/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures ((\result) == 6 - (a) - (b) &&
        (\result) >= 1 &&
        (\result) <= 3 &&
        (\result) != (a) &&
        (\result) != (b));
*/
long func(long a, long b)
{
    long result = 0;

    if (a == 1 && b == 2) {
        result = 3;
    } else if (a == 1 && b == 3) {
        result = 2;
    } else if (a == 2 && b == 1) {
        result = 3;
    } else if (a == 2 && b == 3) {
        result = 1;
    } else if (a == 3 && b == 1) {
        result = 2;
    } else if (a == 3 && b == 2) {
        result = 1;
    }

    //@ assert result == 6 - a - b;
    //@ assert result >= 1;
    //@ assert result <= 3;
    //@ assert result != a;
    //@ assert result != b;

    return result;
}
