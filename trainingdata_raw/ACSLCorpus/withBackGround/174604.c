/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 100;

    lemma a_in_range: \forall integer a; is_in_range(a) ==> a >= 1 && a <= 100;
    lemma b_in_range: \forall integer b; is_in_range(b) ==> b >= 1 && b <= 100;
    lemma c_in_range: \forall integer c; is_in_range(c) ==> c >= 1 && c <= 100;
*/

/*@
    requires is_in_range(a);
    requires is_in_range(b);
    requires is_in_range(c);
    ensures \result == (a <= c && c <= b);
*/
int func(int a, int b, int c) {
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;
    return a <= c && c <= b;
}
