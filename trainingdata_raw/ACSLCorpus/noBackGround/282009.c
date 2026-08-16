/*@
    requires (1 <= (n) <= 100);
    ensures \result == (5 * (n) + 2);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    //@ assert (1 <= (n) <= 100);
    result = 5 * n + 2;
    //@ assert result == (5 * (n) + 2);
    return result;
}
