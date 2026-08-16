/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 10 &&
        1 <= b && b <= 10;

    lemma product_positive:
        \forall integer a, b;
        valid_range(a, b) ==> a * b >= 1;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert valid_range(a, b);
    //@ assert a * b >= 1;
    return a * b;
}

int main() {
    return 0;
}
