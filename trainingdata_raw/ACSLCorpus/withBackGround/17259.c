/*@
    predicate a_leq_b(integer a, integer b) = a <= b;
    predicate b_lt_10(integer b) = b < 10;
    predicate a_leq_9(integer a) = a <= 9;
*/

/*@
    lemma calc_example_2: \forall integer x; x >= 0 ==> 2 * (x + 2) <= 2 * x + 20;
*/

/*@
    lemma proof_ex_2_3: \forall integer a, b; a <= b && b < 10 ==> a <= 9;
*/

int main()
{
    return 0;
}
