/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    
    logic integer area_formula(integer r) = 3 * (r * r);
    
    lemma r_squared_bounds: \forall integer r; r_in_range(r) ==> 1 <= r * r <= 10000;
    lemma area_bounds: \forall integer r; r_in_range(r) ==> 3 <= area_formula(r) <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == area_formula(r);
    assigns \nothing;
*/
long func(long r)
{
    long pi;
    long r_squared;
    long area;
    
    pi = 3;
    
    //@ assert 1 <= r * r <= 10000;
    r_squared = r * r;
    
    //@ assert 3 <= 3 * r_squared <= 30000;
    area = pi * r_squared;
    
    //@ assert area == 3 * (r * r);
    return area;
}
