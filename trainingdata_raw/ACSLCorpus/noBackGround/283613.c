/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
    ensures 1 <= \result <= 3;
    ensures \result != a;
    ensures \result != b;
*/
int func(int a, int b)
{
    int result;

    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    //@ assert a != b;

    result = 6 - a - b;

    //@ assert result == 6 - a - b;
    //@ assert 1 <= result <= 3;
    //@ assert result != a;
    //@ assert result != b;

    return result;
}
