/*@
    predicate non_negative(integer x) = x >= 0;
    predicate non_negative_3(integer x, integer y, integer z) = 
        non_negative(x) && non_negative(y) && non_negative(z);
    predicate ensures_relation(integer x, integer y, integer z) = 
        x <= 2 * (x + y + z);
*/

/*@
    lemma calc_example_2: 
        \forall integer x, y, z; 
        non_negative_3(x, y, z) ==> ensures_relation(x, y, z);
*/

/*@
    requires non_negative_3(x, y, z);
    ensures ensures_relation(x, y, z);
*/
void calc_example_2(int x, int y, int z) {
    //@ assert non_negative(x);
    //@ assert non_negative(y);
    //@ assert non_negative(z);
    //@ assert x <= x + y + z;
    //@ assert x + y + z <= 2 * (x + y + z);
    //@ assert ensures_relation(x, y, z);
}

int main() {
    return 0;
}
