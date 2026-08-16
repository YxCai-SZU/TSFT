/*@
    predicate is_even(integer n) = n >= 0 && n % 2 == 0;
    
    lemma lemma_n_even_is_even:
        \forall integer n; is_even(n) ==> is_even(n);
*/

/*@
    requires n >= 0 && n % 2 == 0;
    ensures \result == 0;
    ensures n >= 0 && n % 2 == 0;
*/
int calc_example_5(int n) {
    //@ assert n >= 0;
    //@ assert n % 2 == 0;
    //@ assert is_even(n);
    return 0;
}

int main() {
    return 0;
}
