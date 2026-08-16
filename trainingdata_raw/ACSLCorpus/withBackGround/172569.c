/*@
    predicate less_than(integer a, integer b) = a < b;

    lemma transitivity:
        \forall integer x, y, z;
            less_than(x, y) && less_than(y, z) ==> less_than(x, z);
*/

/*@
    requires x < y;
    requires y < z;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_2(int x, int y, int z) {
    //@ assert x < y;
    //@ assert y < z;
    //@ assert x < z;
    return 0;
}

/*@
    requires n <= 20;
    requires n >= 0;
    ensures \result == 0;
    assigns \nothing;
*/
int func2(int n) {
    //@ assert n <= 10 || n > 10;
    return 0;
}

int main() {
    return 0;
}
