/*@
    predicate square_nonnegative(integer a) = a * a >= 0;
    predicate square_zero(integer a) = a * a == 0;

    lemma square_positive_zero: \forall integer a; a >= 0 ==> square_nonnegative(a);
    lemma square_negative_zero: \forall integer a; a < 0 ==> square_nonnegative(a);
    lemma square_zero_lemma: \forall integer a; a == 0 ==> square_zero(a);
*/

/*@
    requires a >= 0;
    ensures \result >= 0;
    ensures \result == a * a;
*/
int square_positive(int a) {
    //@ assert a >= 0;
    int result = a * a;
    //@ assert result >= 0;
    //@ assert result == a * a;
    return result;
}

/*@
    requires a < 0;
    ensures \result >= 0;
    ensures \result == a * a;
*/
int square_negative(int a) {
    //@ assert a < 0;
    int result = a * a;
    //@ assert result >= 0;
    //@ assert result == a * a;
    return result;
}

/*@
    requires a == 0;
    ensures \result == 0;
    ensures \result == a * a;
*/
int square_zero_func(int a) {
    //@ assert a == 0;
    int result = a * a;
    //@ assert result == 0;
    //@ assert result == a * a;
    return result;
}

int main() {
    return 0;
}
