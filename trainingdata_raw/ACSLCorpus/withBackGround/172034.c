/*@
    predicate and_nothing(integer a) = (a & 0) == 0;
    predicate or_nothing(integer a) = (a | 0) == a;
    predicate xor_nothing(integer a) = (a ^ 0) == a;
    predicate left_shift_nothing(integer a) = (a << 0) == a;
    predicate right_shift_nothing(integer a) = (a >> 0) == a;
    predicate bitwise_not_nothing(integer a) = a == a;
*/

/*@
    lemma and_nothing_lemma: \forall integer a; and_nothing(a);
    lemma or_nothing_lemma: \forall integer a; or_nothing(a);
    lemma xor_nothing_lemma: \forall integer a; xor_nothing(a);
    lemma left_shift_nothing_lemma: \forall integer a; left_shift_nothing(a);
    lemma right_shift_nothing_lemma: \forall integer a; right_shift_nothing(a);
    lemma bitwise_not_nothing_lemma: \forall integer a; bitwise_not_nothing(a);
*/

int main() {
    unsigned int a;
    
    //@ assert and_nothing(a);
    //@ assert or_nothing(a);
    //@ assert xor_nothing(a);
    //@ assert left_shift_nothing(a);
    //@ assert right_shift_nothing(a);
    //@ assert bitwise_not_nothing(a);
    
    return 0;
}
