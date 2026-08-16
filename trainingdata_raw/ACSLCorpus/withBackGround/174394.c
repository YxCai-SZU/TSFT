/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer func_spec(integer r) = 3 * r * r;
    lemma func_lemma: \forall integer r; r_in_range(r) ==> func_spec(r) <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    unsigned int res;
    //@ assert r >= 1 && r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    res = 3 * r * r;
    return res;
}
