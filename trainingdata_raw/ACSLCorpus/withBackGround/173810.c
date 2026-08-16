/*@
    predicate non_negative(integer n) = 0 <= n;
    predicate within_bound(integer n) = n <= 100;

    lemma sum_bound: \forall integer n; non_negative(n) && within_bound(n) ==> 
        n * (n + 1) / 2 <= 100 * 101 / 2;
*/

/*@
    requires 0 <= n <= 100;
    ensures \result == (n * (n + 1) / 2 <= 100 * 101 / 2);
    assigns \nothing;
*/
int func(int n) {
    int result;
    //@ assert 0 <= n && n <= 100;
    //@ assert n * (n + 1) <= 100 * 101;
    //@ assert n * (n + 1) / 2 <= 100 * 101 / 2;
    result = n * (n + 1) / 2 <= 100 * 101 / 2;
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
