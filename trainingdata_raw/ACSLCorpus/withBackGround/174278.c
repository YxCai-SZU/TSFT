/*@
    predicate is_valid_l(integer l) = 1 <= l && l <= 1000;
    
    logic integer cube_val(integer l) = l * l * l;
    
    lemma cube_bounds: \forall integer l; is_valid_l(l) ==> cube_val(l) <= 1000000000;
*/

/*@
    requires 1 <= l && l <= 1000;
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
long func(long l) {
    long cube;
    long res = 0;
    const long divisor = 27;
    
    //@ assert is_valid_l(l);
    //@ assert cube_val(l) <= 1000000000;
    
    cube = l * l * l;
    
    /*@
        loop invariant 0 <= cube <= cube_val(l);
        loop invariant 0 <= res <= cube_val(l) / 27;
        loop invariant cube == cube_val(l) - res * divisor;
        loop assigns cube, res;
        loop variant cube;
    */
    while (cube >= divisor) {
        cube -= divisor;
        res += 1;
    }
    
    //@ assert cube == cube_val(l) - res * divisor;
    //@ assert res == cube_val(l) / 27;
    
    return res;
}
