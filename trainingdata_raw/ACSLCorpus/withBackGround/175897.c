/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    predicate res_correct(integer r, integer res) = res == r * r;
    lemma square_bound: \forall integer r; r_in_range(r) ==> r * r <= 10000;
*/

/*@
    requires r_in_range(r);
    ensures res_correct(r, \result);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int res;

    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    
    res = r * r;
    return res;
}

int main()
{
    return 0;
}
