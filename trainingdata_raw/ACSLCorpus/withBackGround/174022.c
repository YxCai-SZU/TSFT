/*@
predicate is_positive(integer x) = x > 0;
predicate in_range(integer x) = 0 < x && x < 1000;

lemma calc_example_5:
  \forall integer x, y; x < y ==> x + 2 < y + 3;

lemma square_increasing:
  \forall integer x; in_range(x) ==> x * x < 1000000;
*/

/*@
  requires x < y;
  ensures \result == 1;
*/
int calc_example_5_proof(int x, int y) {
    //@ assert x < y;
    //@ assert x + 2 < y + 3;
    return 1;
}

/*@
  requires 0 < x && x < 1000;
  ensures \result == 1;
*/
int check_square_increasing_proof(int x) {
    //@ assert x * x < 1000000;
    return 1;
}

int main() {
    return 0;
}
