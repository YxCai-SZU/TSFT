/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == (((a) * 3) + (b));
    ensures \result <= (100 * 3) + 100;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert (0 <= (a) <= 100 && 0 <= (b) <= 100);
    result = (a * 3) + b;
    //@ assert result == (((a) * 3) + (b));
    //@ assert result >= 0;
    //@ assert result <= (100 * 3) + 100;
    return result;
}
