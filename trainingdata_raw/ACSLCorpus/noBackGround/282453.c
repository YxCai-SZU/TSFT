/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == ((a) + (b) + 1 - (c)) || \result == 0;
    ensures \result >= 0;
*/
int func(int a, int b, int c)
{
    int result;

    result = a + b + 1 - c;

    if (result > 0)
    {
        //@ assert result == ((a) + (b) + 1 - (c)) || result == 0;
        return result;
    }
    else
    {
        //@ assert result == ((a) + (b) + 1 - (c)) || result == 0;
        return 0;
    }
}
