/*@
predicate range(integer v) = 0 <= v && v <= 100;

predicate sum_le_100(integer x, integer y) = x + y <= 100;

lemma calc_example_6: \forall integer z, w; z + w == w + z;

lemma proof_fn_lemma: \forall integer x, y; range(x) && range(y) && sum_le_100(x, y) ==> sum_le_100(x, y);
*/

/*@
requires range(x) && range(y) && sum_le_100(x, y);
ensures sum_le_100(x, y);
*/
void proof_fn(int x, int y) {
    //@ assert sum_le_100(x, y);
}

int main() {
    return 0;
}
