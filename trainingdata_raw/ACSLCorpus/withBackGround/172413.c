/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;
    logic integer compute_result(integer a) = a * 2 * 3;
*/

/*@
    requires is_valid_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
unsigned int func(unsigned int a) {
    unsigned int pi;
    unsigned int res;

    pi = 3;
    //@ assert a * 2 * pi == a * 2 * 3;
    res = a * 2 * pi;
    return res;
}
