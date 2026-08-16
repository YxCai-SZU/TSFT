/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == ((a) * (c)) || \result == ((a) * (d)) ||
            \result == ((b) * (c)) || \result == ((b) * (d));
    ensures \result >= ((a) * (c));
    ensures \result >= ((a) * (d));
    ensures \result >= ((b) * (c));
    ensures \result >= ((b) * (d));
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int temp_val;

    //@ assert -1000000 <= a * c <= 1000000;
    max_val = a * c;

    //@ assert -1000000 <= a * d <= 1000000;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert -1000000 <= b * c <= 1000000;
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert -1000000 <= b * d <= 1000000;
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d;
    return max_val;
}
