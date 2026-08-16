/*@
predicate square_nonnegative(integer x) = x >= 0 && x <= 46340;

logic integer square(integer x) = x * x;

lemma square_lemma:
    \forall integer x; square_nonnegative(x) ==> square(x) == x * x;
*/

/*@
requires square_nonnegative(10);
ensures \result == 100;
*/
int test() {
    int result;
    //@ assert square(10) == 100;
    result = 100;
    return result;
}

int main() {
    test();
    return 0;
}
