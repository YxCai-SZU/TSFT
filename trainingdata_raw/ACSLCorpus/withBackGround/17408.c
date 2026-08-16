/*@
predicate positive_and_bounded(integer x) =
    x > 0 && x <= 10;

lemma arith_lemma:
    \forall integer x, y;
    positive_and_bounded(x) && positive_and_bounded(y) ==> x + y <= 20;
*/

/*@
requires positive_and_bounded(x);
requires positive_and_bounded(y);
ensures \result == x + y;
ensures \result <= 20;
*/
int arith(int x, int y)
{
    int result;
    //@ assert x + y <= 20;
    result = x + y;
    //@ assert result == x + y;
    return result;
}

int main() {
    return 0;
}
