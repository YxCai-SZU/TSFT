/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 2000);
    ensures \result == b - a * n || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int result;

    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 2000);
    //@ assert ((a) * (n)) <= 2000;

    result = b - a * n;

    if (result < 0) {
        //@ assert result < 0;
        result = 0;
    }
    //@ assert result >= 0;
    //@ assert result == b - a * n || result == 0;
    return result;
}
