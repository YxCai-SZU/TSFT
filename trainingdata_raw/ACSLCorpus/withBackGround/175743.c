/*@
predicate leq(integer a, integer b) = a <= b;

lemma calc_example_10: \forall integer a, b; leq(a, b) ==> 2 * a <= 2 * b;
lemma calc_example_20: \forall integer a, b, c; leq(a, b) && leq(b, c) ==> 2 * a <= 2 * c;
lemma calc_example_30: \forall integer a, b, c, d; leq(a, b) && leq(b, c) && leq(c, d) ==> 2 * a <= 2 * d;
lemma func_example_40: \forall integer a, b; leq(a, b) ==> 3 * a <= 3 * b;
lemma func_example_50: \forall integer a, b, c; leq(a, b) && leq(b, c) ==> 3 * a <= 3 * c;
*/

void main() {
    int a;
    int b;
    int c;
    int d;
    
    //@ assert leq(a, b) ==> 2 * a <= 2 * b;
    //@ assert leq(a, b) && leq(b, c) ==> 2 * a <= 2 * c;
    //@ assert leq(a, b) && leq(b, c) && leq(c, d) ==> 2 * a <= 2 * d;
    //@ assert leq(a, b) ==> 3 * a <= 3 * b;
    //@ assert leq(a, b) && leq(b, c) ==> 3 * a <= 3 * c;
}
