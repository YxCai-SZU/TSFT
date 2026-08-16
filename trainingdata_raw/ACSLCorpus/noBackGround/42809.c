/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures \result >= a + c;
    ensures \result >= a + d;
    ensures \result >= b + c;
    ensures \result >= b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }

    if (c > d) {
        max2 = c;
    } else {
        max2 = d;
    }

    result = max1 + max2;

    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;
    //@ assert result >= a + c;
    //@ assert result >= a + d;
    //@ assert result >= b + c;
    //@ assert result >= b + d;

    return result;
}
