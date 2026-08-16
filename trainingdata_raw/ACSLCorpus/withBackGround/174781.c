/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 20;
    predicate valid_inputs(integer a, integer b, integer c, integer d) =
        is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
*/

/*@
    requires valid_inputs(a, b, c, d);
    ensures is_in_range(\result);
*/
int func(int a, int b, int c, int d) {
    int tmp_a;
    int tmp_b;
    int tmp_c;
    int tmp_d;
    int res;

    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
    
    tmp_a = (a > b) ? a : b;
    tmp_b = (a > b) ? b : a;
    tmp_c = (c > d) ? c : d;
    tmp_d = (c > d) ? d : c;
    
    //@ assert is_in_range(tmp_a) && is_in_range(tmp_b) && is_in_range(tmp_c) && is_in_range(tmp_d);
    
    if (tmp_b < tmp_c) {
        res = tmp_a;
        //@ assert is_in_range(res);
        return res;
    }
    
    if (tmp_c < tmp_b && tmp_a < tmp_d) {
        res = tmp_d;
        //@ assert is_in_range(res);
        return res;
    }
    
    if (tmp_b < tmp_d) {
        //@ assert is_in_range(tmp_b);
        res = tmp_b;
        //@ assert is_in_range(res);
        return res;
    }
    
    res = tmp_a;
    //@ assert is_in_range(res);
    return res;
}
