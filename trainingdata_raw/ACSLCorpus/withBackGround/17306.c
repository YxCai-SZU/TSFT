/*@
predicate double_leq(integer x) = x + x <= 2 * x;

lemma double_lemma:
    \forall integer x; double_leq(x);

lemma double_mon_lemma:
    \forall integer x, y; x >= y ==> x + x >= y + y;
*/

/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert 5 + 5 <= 2 * 5;
    //@ assert 5 + 5 >= 3 + 3;
    return 0;
}
