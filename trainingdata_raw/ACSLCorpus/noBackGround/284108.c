/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 2 * 3);
    assigns \nothing;
*/
int func(int n)
{
    int pi;
    int result;

    pi = 3;
    result = n * 2 * pi;

    //@ assert result == n * 2 * 3;
    return result;
}
