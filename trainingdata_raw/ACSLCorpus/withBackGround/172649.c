/*@
    predicate division_property_lemma(integer n) = n > 0 ==> n / 2 <= n;
*/

/*@
    requires n > 0;
    ensures \result == 1;
    assigns \nothing;
*/
int division_property(int n) {
    int result;
    int temp;

    //@ assert n > 0;
    temp = n / 2;
    //@ assert temp >= 0;
    //@ assert temp <= n;
    result = 1;
    return result;
}

int main() {
    return 0;
}
