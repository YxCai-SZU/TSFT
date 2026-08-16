/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <= c;
    ensures \result >= c - 2 * a - 2 * b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int diff;

    result = c;

    if (a > b) {
        diff = a - b;
    } else {
        diff = b - a;
    }
    result = result - diff;

    //@ assert ((diff) == ((a) > (b) ? (a) - (b) : (b) - (a)) &&         (diff) >= 0 &&         (diff) <= (a) + (b));
    //@ assert diff >= 0;
    //@ assert diff <= a + b;

    if (result < 0) {
        result = 0;
    }

    //@ assert result <= c;
    //@ assert result >= c - 2 * a - 2 * b;

    return result;
}
