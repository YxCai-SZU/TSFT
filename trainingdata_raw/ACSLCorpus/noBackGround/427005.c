/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    result = 0;

    if (a < b && b < c) {
        result = 1;
    } else {
        result = 0;
    }

    //@ assert result == 1 <==> ((a) < (b) && (b) < (c));

    return result;
}
