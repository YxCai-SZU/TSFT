/*@
predicate a_gt_b(integer a, integer b) = a > b;
predicate b_ge_c(integer b, integer c) = b >= c;
predicate a_ge_c(integer a, integer c) = a >= c;

lemma func_lemma:
    \forall integer a, b, c;
    a_gt_b(a, b) && b_ge_c(b, c) ==> a_ge_c(a, c);

lemma func2_lemma:
    \forall integer a, b, c;
    a_gt_b(a, b) && b_ge_c(b, c) ==> a_ge_c(a, c);
*/

/*@
requires a > b;
requires b >= c;
ensures \result == 0;
assigns \nothing;
*/
int func(unsigned char a, unsigned char b, unsigned char c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
    return 0;
}

/*@
requires a > b;
requires b >= c;
ensures \result == 0;
assigns \nothing;
*/
int func2(unsigned char a, unsigned char b, unsigned char c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
    return 0;
}

int main() {
    return 0;
}
