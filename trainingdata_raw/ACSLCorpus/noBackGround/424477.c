/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    requires 1 <= c && c <= 10000;
    requires 1 <= d && d <= 10000;
    ensures \result <= 20000;
    ensures \result == ((a) <= (b) ?
            ((c) <= (d) ? (a) + (c) : (a) + (d))
        :
            ((c) <= (d) ? (b) + (c) : (b) + (d)));
*/
int compute_func(int a, int b, int c, int d)
{
    int result;

    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert (1 <= (c) && (c) <= 10000);
    //@ assert (1 <= (d) && (d) <= 10000);

    if (a <= b) {
        if (c <= d) {
            result = a + c;
        } else {
            result = a + d;
        }
    } else {
        if (c <= d) {
            result = b + c;
        } else {
            result = b + d;
        }
    }

    //@ assert result <= 20000;
    return result;
}

int main()
{
    return 0;
}
