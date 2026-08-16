/*@
predicate positive_params(integer x, integer y, integer z) =
    x > 0 && y > 0 && z > 0;

lemma calc_example_5:
    \forall integer x, y, z;
    positive_params(x, y, z) ==>
    2 * x * (y + z) == (x + x) * (y + z);
*/

/*@
    requires x > 0 && y > 0 && z > 0;
    ensures \result == 1;
*/
int example(int x, int y, int z) {
    //@ assert x > 0 && y > 0 && z > 0;
    return 1;
}
