/*@
    requires -1000 <= a && a <= 1000;
    requires -1000 <= b && b <= 1000;
    requires -1000 <= c && c <= 1000;
    requires -1000 <= d && d <= 1000;
    ensures \result == ((a * c <= b * d) || (a * d <= b * c));
    assigns \nothing;
*/
int non_linear_arith_example10(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int result;

    //@ assert -1000 <= a && a <= 1000;
    //@ assert -1000 <= b && b <= 1000;
    //@ assert -1000 <= c && c <= 1000;
    //@ assert -1000 <= d && d <= 1000;

    //@ assert (-1000000 <= (a) * (c) && (a) * (c) <= 1000000);
    //@ assert (-1000000 <= (a) * (d) && (a) * (d) <= 1000000);
    //@ assert (-1000000 <= (b) * (c) && (b) * (c) <= 1000000);
    //@ assert (-1000000 <= (b) * (d) && (b) * (d) <= 1000000);

    //@ assert a * c <= 1000000 && a * d <= 1000000 && b * c <= 1000000 && b * d <= 1000000;
    //@ assert a * c >= -1000000 && a * d >= -1000000 && b * c >= -1000000 && b * d >= -1000000;

    result = (a * c <= b * d) || (a * d <= b * c);
    return result;
}
