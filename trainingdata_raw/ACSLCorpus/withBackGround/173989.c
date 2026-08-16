/*@
    predicate multiplication_property_lemma(integer n) = n > 0 ==> n * n <= n * n;
*/

/*@
    requires n > 0;
    ensures \result == n * n;
    assigns \nothing;
*/
int multiply(int n) {
    //@ assert n > 0;
    int result = n * n;
    //@ assert result == n * n;
    return result;
}

int main() {
    int x = 5;
    //@ assert x > 0;
    int r = multiply(x);
    //@ assert r == x * x;
    return 0;
}
