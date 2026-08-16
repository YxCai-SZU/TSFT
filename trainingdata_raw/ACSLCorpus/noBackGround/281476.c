/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d || \result == c * b;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int temp;

    //@ assert -100000000 <= a * c <= 100000000;
    max_val = a * c;

    //@ assert -100000000 <= a * d <= 100000000;
    temp = a * d;
    if (temp > max_val) {
        max_val = temp;
    }

    //@ assert -100000000 <= b * c <= 100000000;
    temp = b * c;
    if (temp > max_val) {
        max_val = temp;
    }

    //@ assert -100000000 <= b * d <= 100000000;
    temp = b * d;
    if (temp > max_val) {
        max_val = temp;
    }

    //@ assert -100000000 <= c * b <= 100000000;
    temp = c * b;
    if (temp > max_val) {
        max_val = temp;
    }

    //@ assert max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d || max_val == c * b;
    return max_val;
}
