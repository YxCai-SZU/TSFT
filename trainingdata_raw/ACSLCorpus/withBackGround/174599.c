/*@
predicate is_nonzero(integer r) = r != 0;
predicate in_range(integer r) = -20 <= r && r <= 20;

lemma func_lemma: \forall integer r; in_range(r) && is_nonzero(r) ==> 1 * r * r == r * r;
*/

/*@
requires -20 <= r <= 20;
requires r != 0;
ensures 1 * r * r == r * r;
*/
void func(int r) {
    //@ assert 1 * r == r;
    //@ assert 1 * r * r == r * r;
}

int main() {
    return 0;
}
