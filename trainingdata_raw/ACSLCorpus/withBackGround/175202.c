/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;
    predicate product_in_range(integer x, integer y, integer res) =
        res == x * y && res <= 10000;
*/

/*@
    requires valid_range(x) && valid_range(y);
    ensures product_in_range(x, y, \result);
*/
unsigned int func(unsigned int x, unsigned int y) {
    unsigned int res;
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert x * y <= 10000;
    res = x * y;
    return res;
}
