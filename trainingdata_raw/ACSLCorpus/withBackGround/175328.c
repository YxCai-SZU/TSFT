/*@
    predicate bounds(integer x) = -100 <= x <= 100;

    lemma calc_example_3:
        \forall integer a, b; a == 5 && b == 2 * a ==> b - 5 == a;

    lemma check_bounds:
        \forall integer x; bounds(x) ==> 
            x + 1 <= 101 &&
            x + 2 <= 102 &&
            x + 3 <= 103 &&
            x + 4 <= 104 &&
            x + 5 <= 105;
*/

/*@
    requires bounds(x);
    ensures \result == 1;
*/
int example_usage(int x) {
    //@ assert bounds(x);
    
    //@ assert x + 1 <= 101;
    //@ assert x + 2 <= 102;
    //@ assert x + 3 <= 103;
    //@ assert x + 4 <= 104;
    //@ assert x + 5 <= 105;
    
    return 1;
}

int main() {
    return 0;
}
