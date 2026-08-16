/*@
    requires 0 <= x <= 10000;
    requires 0 <= y <= 10000;
    ensures \result == x + y;
    ensures \result <= 10000 + 10000;
*/
int add_with_bounds(int x, int y) {
    int result;
    //@ assert (0 <= (x) <= 10000 && 0 <= (y) <= 10000);
    result = x + y;
    //@ assert result == x + y;
    //@ assert result <= 10000 + 10000;
    return result;
}
