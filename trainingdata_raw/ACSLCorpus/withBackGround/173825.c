/*@
    predicate is_even(integer x) = x % 2 == 0;
    
    lemma m_plus_2_even: \forall integer m; is_even(m) ==> is_even(m + 2);
    lemma n_plus_2_even: \forall integer n; is_even(n) ==> is_even(n + 2);
    lemma sum_even: \forall integer m, n; is_even(m) && is_even(n) ==> is_even(m + n);
    lemma final_even: \forall integer m, n; is_even(m) && is_even(n) ==> is_even(m + n + 2);
*/

/*@
    requires m % 2 == 0;
    requires n % 2 == 0;
    ensures (m + n + 2) % 2 == 0;
*/
void calc_example_15(int m, int n) {
    //@ assert m % 2 == 0;
    //@ assert n % 2 == 0;
    //@ assert (m + 2) % 2 == 0;
    //@ assert (n + 2) % 2 == 0;
    //@ assert ((m + 2) + (n + 2)) % 2 == 0;
    //@ assert (m + n + 2) % 2 == 0;
}

int main() {
    return 0;
}
