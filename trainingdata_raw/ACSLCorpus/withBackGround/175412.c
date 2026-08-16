/*@
    predicate is_in_range(integer a) = 1 <= a && a <= 10;

    logic integer compute_result(integer a) = a + a * a + a * a * a;

    lemma result_lower_bound: \forall integer a; is_in_range(a) ==> compute_result(a) >= 3;
    lemma result_upper_bound: \forall integer a; is_in_range(a) ==> compute_result(a) <= 1110;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
long func(long a)
{
    long a_1;
    long a_2;
    long a_3;
    long ans;

    //@ assert 1 <= a <= 10;
    //@ assert a + a * a + a * a * a >= 3;
    //@ assert a + a * a + a * a * a <= 1110;

    a_1 = a;
    a_2 = a * a;
    a_3 = a * a * a;
    ans = a_1 + a_2 + a_3;

    //@ assert ans == a + a * a + a * a * a;
    return ans;
}
