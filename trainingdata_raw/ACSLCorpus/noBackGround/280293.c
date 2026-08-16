/*@
    requires 1 <= r <= 100;
    ensures \result == r * 2 * 3;
*/
int func(int r)
{
    int pi;
    int result;

    pi = 3;
    result = r * 2 * pi;
    //@ assert result == r * 2 * 3;
    return result;
}
