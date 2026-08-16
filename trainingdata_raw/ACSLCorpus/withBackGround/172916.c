/*@
    predicate a_in_range(integer a) = -10 <= a && a <= 10;
    predicate square_in_range(integer a) = -1000 <= a * a && a * a <= 1000;
    predicate cube_in_range(integer a) = -1000 <= a * a * a && a * a * a <= 1000;
    lemma square_bound: \forall integer a; a_in_range(a) ==> square_in_range(a);
    lemma cube_bound: \forall integer a; a_in_range(a) ==> cube_in_range(a);
*/

/*@
    requires a_in_range(a);
    ensures \result == a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert a_in_range(a);
    //@ assert square_in_range(a);
    //@ assert cube_in_range(a);

    result = a * a * a;
    return result;
}
