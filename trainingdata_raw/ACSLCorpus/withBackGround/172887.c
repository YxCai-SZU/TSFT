/*@
    predicate lower_bound(integer x) = 1 <= x;
    predicate upper_bound(integer x) = x <= 100;
    logic integer expression(integer x) = 2 * x + 1;
*/

/*@
    lemma calc_example_6:
        \forall integer x;
            lower_bound(x) && upper_bound(x) ==>
            (3 <= expression(x)) && (expression(x) <= 201);
*/

int main() {
    //@ assert \true;
    return 0;
}
