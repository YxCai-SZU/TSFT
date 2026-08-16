/*@
predicate non_negative(integer x) = x >= 0;

lemma additive_monoid_on_int:
    \forall integer a, b;
        non_negative(a) && non_negative(b) ==> a + b >= 0;
*/

/*@
    requires a >= 0;
    requires b >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int additive_monoid_on_int(int a, int b) {
    //@ assert a >= 0;
    //@ assert b >= 0;
    int result = a + b;
    //@ assert result >= 0;
    return result;
}

int main() {
    return 0;
}
