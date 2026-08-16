/*@
predicate nonnegative(integer x) = x >= 0;

lemma add_sub_idempotent:
    \forall integer x; nonnegative(x) ==> x + 1 - 1 == x;
*/

/*@
requires nonnegative(x);
ensures \result == x;
*/
int add_and_subtract(int x) {
    //@ assert nonnegative(x);
    int result = x + 1 - 1;
    //@ assert result == x;
    return result;
}

int main() {
    return 0;
}
