/*@
    requires (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000) && (-1000 <= (c) && (c) <= 1000) && (-1000 <= (d) && (d) <= 1000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res1;
    int res2;
    int res3;
    int res4;
    int result;

    //@ assert (-1000000 <= (a) * (c) && (a) * (c) <= 1000000);
    res1 = a * c;

    //@ assert (-1000000 <= (a) * (d) && (a) * (d) <= 1000000);
    res2 = a * d;

    //@ assert (-1000000 <= (b) * (c) && (b) * (c) <= 1000000);
    res3 = b * c;

    //@ assert (-1000000 <= (b) * (d) && (b) * (d) <= 1000000);
    res4 = b * d;

    if (res1 > res2) {
        if (res1 > res3) {
            if (res1 > res4) {
                result = res1;
            } else {
                result = res4;
            }
        } else {
            if (res3 > res4) {
                result = res3;
            } else {
                result = res4;
            }
        }
    } else {
        if (res2 > res3) {
            if (res2 > res4) {
                result = res2;
            } else {
                result = res4;
            }
        } else {
            if (res3 > res4) {
                result = res3;
            } else {
                result = res4;
            }
        }
    }

    //@ assert result == a * c || result == a * d || result == b * c || result == b * d;
    return result;
}
