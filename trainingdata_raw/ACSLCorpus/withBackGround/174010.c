/*@
predicate valid_u32(integer v) = 0 <= v && v <= 4294967295;

lemma comm_and_property:
    \forall integer x, y; valid_u32(x) && valid_u32(y) ==> (x & y) == (y & x);
*/

/*@
requires valid_u32(x) && valid_u32(y);
ensures \result == ((x & y) == (y & x));
assigns \nothing;
*/
int func(unsigned int x, unsigned int y) {
    // Variable declarations at top of scope
    int res;
    
    //@ assert valid_u32(x);
    //@ assert valid_u32(y);
    
    res = ((x & y) == (y & x));
    return res;
}
