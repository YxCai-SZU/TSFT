/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    ensures \result >= 0;
*/
int func(int r)
{
    int res;
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r >= 0;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r >= 0;
    //@ assert 3 * r * r <= 30000;
    res = 3 * r * r;
    return res;
}
