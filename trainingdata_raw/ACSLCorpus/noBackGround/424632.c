/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= b;
    ensures (b - a * 2 > 0) ==> \result == b - a * 2;
    ensures (b - a * 2 <= 0) ==> \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    result = b - a * 2;
    //@ assert result == b - a * 2;
    if (result < 0)
    {
        result = 0;
    }
    //@ assert result >= 0;
    //@ assert result <= b;
    //@ assert (b - a * 2 > 0) ==> result == b - a * 2;
    //@ assert (b - a * 2 <= 0) ==> result == 0;
    return result;
}
