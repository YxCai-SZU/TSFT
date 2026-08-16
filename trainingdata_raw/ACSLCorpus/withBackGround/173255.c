/*@
    predicate non_negative(integer n) = n >= 0;

    //@ logic integer prod_of_natural(integer n) = (n <= 0) ? 1 : n * prod_of_natural(n - 1);

    //@ lemma prod_non_zero: \forall integer n; non_negative(n) ==> prod_of_natural(n) != 0;
*/

/*@
    assigns \nothing;
    ensures \result == 0;
*/
int main() {
    //@ assert non_negative(0);
    return 0;
}
