/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer circumference(integer r) = 2 * 3 * r;
    lemma circumference_bound: \forall integer r; r_in_range(r) ==> circumference(r) <= 2 * 3 * 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == circumference(r);
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    //@ assert r_in_range(r);
    //@ assert circumference(r) <= 2 * 3 * 100;
    return 2 * 3 * r;
}

/*@
    requires r_in_range(r);
    ensures \result == circumference(r);
    assigns \nothing;
*/
unsigned int func1(unsigned int r)
{
    //@ assert r_in_range(r);
    //@ assert circumference(r) <= 2 * 3 * 100;
    //@ assert circumference(r) == circumference(r);
    return 2 * 3 * r;
}

/*@
    requires r_in_range(r);
    ensures \result == circumference(r);
    assigns \nothing;
*/
unsigned int func2(unsigned int r)
{
    //@ assert r_in_range(r);
    //@ assert circumference(r) <= 2 * 3 * 100;
    //@ assert circumference(r) == circumference(r);
    //@ assert circumference(r) <= 2 * 3 * 100;
    return 2 * 3 * r;
}
