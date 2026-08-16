/*@
predicate less_than(integer a, integer b) = a < b;

lemma calc_less_than:
    \forall integer x, y;
        less_than(x, y) ==> less_than(x, y + 1);

lemma y_n_greater_than_x:
    \forall integer x, y, n;
        less_than(x, y) && n > 0 ==> less_than(x, y + n);
*/

/*@
    requires x < y;
    ensures \result == 0;
*/
int example_4(int x, int y) {
    //@ assert x < y;
    //@ assert x < y + 1;
    return 0;
}

/*@
    requires x < y;
    requires n > 0;
    ensures \result == 0;
*/
int example_5(int x, int y, int n) {
    //@ assert x < y;
    //@ assert n > 0;
    //@ assert x < y + n;
    return 0;
}

int main() {
    return 0;
}
