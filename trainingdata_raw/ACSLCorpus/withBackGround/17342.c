/*@
    predicate is_nonzero(integer x) = x != 0;

    lemma negative_on_negative:
        \forall integer x; is_nonzero(x) ==> -(-x) == x;

    lemma negative_on_negative_negative:
        \forall integer x; is_nonzero(x) ==> -(-(-x)) == -x;

    lemma negative_on_negative_negative_negative:
        \forall integer x; is_nonzero(x) ==> -(-(-(-x))) == x;

    lemma example:
        \forall integer x; is_nonzero(x) ==> -(-(-(-(-x)))) == -x;
*/

int main() {
    int x;
    //@ assert \true;
    return 0;
}
