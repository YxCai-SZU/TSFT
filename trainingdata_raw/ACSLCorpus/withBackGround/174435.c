/*@
    predicate depth_bounded(integer d) = 0 <= d && d <= 100000;
    
    logic integer boiling_point_adjustment_logic(integer depth) =
        depth;
    
    lemma conversion_valid: \forall integer d; depth_bounded(d) ==> (integer)d == d;
*/

/*@
    requires depth_bounded(depth);
    ensures \result == boiling_point_adjustment_logic(depth);
    assigns \nothing;
*/
int boiling_point_adjustment(unsigned int depth) {
    // Variable declarations at top of scope
    int ret;
    
    //@ assert depth_bounded(depth);
    
    //@ ghost int depth_i32 = (int)depth;
    //@ assert depth_i32 == boiling_point_adjustment_logic(depth);
    
    ret = 1 * ((int)depth);
    
    //@ assert ret == boiling_point_adjustment_logic(depth);
    return ret;
}

int main() {
    return 0;
}
