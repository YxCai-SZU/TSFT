/*@
predicate min_value(integer x, integer y, integer result) =
    (x < y ==> result == x) &&
    (x >= y ==> result == y);

lemma min_property:
    \forall integer x, y;
        x < y ==> min_value(x, y, x);
*/

/*@
    requires \true;
    ensures \true;
*/
void example_min_usage(void) {
    //@ assert min_value(5, 3, 3);
    //@ assert min_value(10, 8, 8);
}

int main() {
    example_min_usage();
    return 0;
}
