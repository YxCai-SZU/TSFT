/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert 1 <= a * b <= 10000;
    //@ assert a * b == a * b;

    result = a * b;
    return result;
}
