/*@
    predicate f_monotonic(integer x) = x >= 1;
    predicate f_monotonic2(integer x) = x >= 2;
    predicate axiom_f_decrement(integer x) = x >= 1;
    predicate calc_example_5(integer x) = x >= 3;
    
    lemma monotonic_lemma: \forall integer x; f_monotonic(x) ==> x >= 1;
    lemma monotonic2_lemma: \forall integer x; f_monotonic2(x) ==> x >= 2;
    lemma decrement_lemma: \forall integer x; axiom_f_decrement(x) ==> x >= 1;
    lemma calc_lemma: \forall integer x; calc_example_5(x) ==> x >= 3;
*/

int main()
{
    return 0;
}
