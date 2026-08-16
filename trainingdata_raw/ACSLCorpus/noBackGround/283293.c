/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == a + b + 10 * c ||
            \result == a + c + 10 * b ||
            \result == b + c + 10 * a;
*/
int func(int a, int b, int c)
{
    int max1;
    int max2;
    int result;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }

    if (max1 > c) {
        max2 = max1;
    } else {
        max2 = c;
    }

    if (max2 == a) {
        result = b + c + 10 * a;
    } else if (max2 == b) {
        result = a + c + 10 * b;
    } else {
        result = a + b + 10 * c;
    }

    //@ assert result == a + b + 10 * c || result == a + c + 10 * b || result == b + c + 10 * a;
    return result;
}
