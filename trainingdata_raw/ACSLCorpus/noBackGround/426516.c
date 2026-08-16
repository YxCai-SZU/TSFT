/*@
    requires ((l) >= 0) && ((l) <= 1290);
    ensures \result == ((l) * (l) * (l));
    assigns \nothing;
*/
int volume_cube(int l) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert 0 <= l && l <= 1290;
    
    //@ assert l * l <= 1290 * 1290;
    
    //@ assert l * l * l <= 1290 * 1290 * 1290;
    
    result = l * l * l;
    return result;
}
