/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer func_result(integer r) = 3 * r * r;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_result(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * 100 * r <= 3 * 100 * 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    result = 3 * r * r;
    return result;
}
