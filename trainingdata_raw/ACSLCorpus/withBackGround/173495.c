/*@
    logic integer double_val(integer x) = x * 2;

    lemma double_greater:
        \forall integer x; x > 0 ==> double_val(x) > x;
*/

/*@
    requires x > 0;
    ensures \result == double_val(x);
    ensures \result > x;
*/
int compute_double(int x) {
    //@ assert x > 0;
    int result;
    result = x * 2;
    //@ assert result == double_val(x);
    //@ assert result > x;
    return result;
}

int main() {
    int x = 5;
    int doubled = compute_double(x);
    return 0;
}
