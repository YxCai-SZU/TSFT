/*@
    predicate valid_date(integer m, integer d) =
        m > 0 && m <= 12 && d > 0 && d <= 31;

    predicate date_relation(integer m1, integer d1, integer m2, integer d2) =
        valid_date(m1, d1) && valid_date(m2, d2) &&
        ((m1 != m2) || (d1 < d2));

    lemma m1_neq_m2_implies_result_one:
        \forall integer m1, d1, m2, d2;
            date_relation(m1, d1, m2, d2) && m1 != m2 ==> 1 == 1 || 1 == 0;

    lemma m1_eq_m2_and_d1_lt_d2_implies_result_zero:
        \forall integer m1, d1, m2, d2;
            date_relation(m1, d1, m2, d2) && m1 == m2 && d1 < d2 ==> 0 == 1 || 0 == 0;
*/

/*@
    requires date_relation(m1, d1, m2, d2);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> m1 != m2;
    ensures \result == 0 ==> m1 == m2 && d1 < d2;
*/
unsigned int func(unsigned int m1, unsigned int d1,
                  unsigned int m2, unsigned int d2)
{
    unsigned int result;

    if (m1 != m2) {
        //@ assert m1 != m2;
        result = 1;
    } else {
        //@ assert m1 == m2 && d1 < d2;
        result = 0;
    }

    return result;
}
