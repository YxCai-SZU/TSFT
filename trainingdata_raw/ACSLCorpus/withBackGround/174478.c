/*@
    predicate leq(integer a, integer b) = a <= b;
    predicate eq(integer a, integer b) = a == b;

    lemma calc_context_example_1: \forall integer a, b; leq(a, b) ==> leq(a, b);
    lemma calc_context_example_2: \forall integer a, b; eq(a, b) ==> eq(a, b);
    lemma calc_context_example_3: \forall integer a, b, c; leq(a, b) && leq(b, c) ==> leq(a, c);
    lemma calc_context_example_4: \forall integer a, b, c; eq(a, b) && eq(b, c) ==> eq(a, c);
    lemma calc_context_example_5: \forall integer a, b, c, d; leq(a, b) && leq(b, c) && leq(c, d) ==> leq(a, d);
    lemma calc_context_example_6: \forall integer a, b, c, d; eq(a, b) && eq(b, c) && eq(c, d) ==> eq(a, d);
*/

int main() {
    int a;
    int b;
    int c;
    int d;
    
    // Example 1: a <= b implies a <= b
    //@ assert leq(a, b) ==> leq(a, b);
    
    // Example 2: a == b implies a == b
    //@ assert eq(a, b) ==> eq(a, b);
    
    // Example 3: a <= b <= c implies a <= c
    //@ assert leq(a, b) && leq(b, c) ==> leq(a, c);
    
    // Example 4: a == b == c implies a == c
    //@ assert eq(a, b) && eq(b, c) ==> eq(a, c);
    
    // Example 5: a <= b <= c <= d implies a <= d
    //@ assert leq(a, b) && leq(b, c) && leq(c, d) ==> leq(a, d);
    
    // Example 6: a == b == c == d implies a == d
    //@ assert eq(a, b) && eq(b, c) && eq(c, d) ==> eq(a, d);
    
    return 0;
}
