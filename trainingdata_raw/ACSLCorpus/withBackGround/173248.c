/*@
    logic integer evenness(integer x) = (x % 2 == 0) ? 0 : 1;

    lemma evenness_lemma:
        \forall integer x; x % 2 == 0 ==> evenness(x) == 0;
*/

void main() {
    //@ assert evenness(100) == 0;
}
