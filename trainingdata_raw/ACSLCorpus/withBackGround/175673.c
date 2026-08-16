/*@
    predicate is_even(integer n) = n % 2 == 0 ==> (n / 2) * 2 == n;
    
    lemma is_even_lemma: \forall integer n; n % 2 == 0 ==> (n / 2) * 2 == n;
*/

int main() {
    //@ assert \true;
    return 0;
}
