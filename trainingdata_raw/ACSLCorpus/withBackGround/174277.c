/*@
    predicate non_negative(integer r, integer b, integer n) =
        r >= 0 && b >= 0 && n >= 0 && r + b >= n;

    predicate result_non_negative(integer r, integer b, integer n) =
        r + b - n >= 0;

    lemma func_lemma:
        \forall integer r, b, n;
        non_negative(r, b, n) ==> result_non_negative(r, b, n);
*/

/*@
    requires non_negative(r, b, n);
    ensures result_non_negative(r, b, n);
*/
void func(int r, int b, int n) {
    //@ assert non_negative(r, b, n);
    //@ assert result_non_negative(r, b, n);
}
