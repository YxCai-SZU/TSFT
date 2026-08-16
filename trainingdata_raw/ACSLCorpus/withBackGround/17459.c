/*@
    logic integer min(integer x, integer y) = (x <= y) ? x : y;

    lemma min_property:
        \forall integer x, y;
            min(x, y) <= x && min(x, y) <= y;

    lemma example_min_usage:
        min(3, 5) <= 3 && min(5, 3) <= 3;
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert min(3, 5) <= 3;
    //@ assert min(5, 3) <= 3;
    
    return 0;
}
