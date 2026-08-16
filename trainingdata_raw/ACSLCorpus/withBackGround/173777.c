/*@
    predicate side_in_range(integer s) = 0 <= s <= 1000;
    predicate result_correct(integer s, integer r) = r == 6 * s * s && r >= 0;
*/

/*@
    requires side_in_range(side);
    ensures result_correct(side, \result);
    assigns \nothing;
*/
int surfacearea_cube(int side) {
    int ret;
    //@ assert side >= 0;
    //@ assert side <= 1000;
    //@ assert 6 * side <= 6000;
    //@ assert 6 * side * side <= 6000 * 1000;
    //@ assert 6 * side * side >= 0;
    ret = 6 * side * side;
    return ret;
}
