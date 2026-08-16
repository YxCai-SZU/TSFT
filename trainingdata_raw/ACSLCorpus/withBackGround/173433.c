/*@
    predicate radius_in_range(integer r) = 0 <= r && r <= 100;
    logic integer area_formula(integer r) = 3 * r * r;
    lemma r_sq_bound: \forall integer r; radius_in_range(r) ==> r * r <= 10000;
    lemma area_bound: \forall integer r; radius_in_range(r) ==> area_formula(r) <= 30000;
*/

/*@
    requires radius_in_range(r);
    ensures \result == area_formula(r);
    assigns \nothing;
*/
int func(int r)
{
    int area;
    //@ assert radius_in_range(r);
    //@ assert r * r <= 10000;
    //@ assert 3 * r * r <= 30000;
    area = 3 * r * r;
    return area;
}
