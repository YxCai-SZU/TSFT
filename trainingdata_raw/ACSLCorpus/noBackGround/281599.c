/*@
    requires 0 <= a && a <= 1000;
    requires 0 <= b && b <= 1000;
    requires 0 <= c && c <= 1000;
    ensures \result == 0;
    assigns \nothing;
*/
int non_linear_arith_check(int a, int b, int c)
{
    //@ assert (0 <= (a) && (a) <= 1000 &&         0 <= (b) && (b) <= 1000 &&         0 <= (c) && (c) <= 1000);
    //@ assert 0 <= a * b * c;
    //@ assert a * b * c <= 1000 * 1000 * 1000;
    return 0;
}
