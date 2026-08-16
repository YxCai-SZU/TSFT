/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(s);
    requires valid_range(w);
    ensures \result == (w >= s);
*/
_Bool func(unsigned int s, unsigned int w)
{
    // Variable declarations at top of scope
    _Bool result;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;

    result = w >= s;
    return result;
}
