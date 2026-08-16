/*@
    requires 1 <= s <= 100;
    ensures \result == s * s;
    ensures \result >= 1;
    ensures \result <= 10000;
*/
int func(int s)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= s <= 100;
    //@ assert s * s >= 1;
    //@ assert s * s <= 10000;
    //@ assert s * s == s * s;

    result = s * s;
    return result;
}
