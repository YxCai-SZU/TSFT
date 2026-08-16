/*@
predicate within_range(integer x, integer y) = x <= y && y <= 10;

lemma example_10: \forall integer x, integer y; within_range(x, y) ==> x <= 10;
*/

/*@
requires within_range(x, y);
ensures \result == 0;
assigns \nothing;
*/
int example_10(int x, int y) {
    //@ assert x <= 10;
    return 0;
}

int main() {
    return 0;
}
