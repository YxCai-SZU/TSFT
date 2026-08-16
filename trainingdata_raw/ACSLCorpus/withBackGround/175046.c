/*@
    predicate non_negative(integer x) = x >= 0;

    lemma calc_example_5: \forall integer x; non_negative(x) ==> 2*x + 3*x == 5*x;
*/

/*@
    requires x >= 0;
    ensures \result == 5*x;
*/
int example(int x) {
    int result;
    int temp1;
    int temp2;

    //@ assert x >= 0;
    //@ assert 2*x <= 2*x + 3*x;
    //@ assert 2*x + 3*x <= 5*x;

    temp1 = 2 * x;
    temp2 = 3 * x;
    result = temp1 + temp2;

    //@ assert result == 5*x;
    return result;
}

int main() {
    return 0;
}
