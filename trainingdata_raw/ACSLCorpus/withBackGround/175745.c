/*@
predicate is_five(integer a) = a == 5;
predicate is_double(integer a, integer b) = b == 2 * a;
predicate is_minus_five(integer b, integer c) = c == b - 5;
predicate is_equal(integer c, integer a) = c == a;
predicate is_double_c(integer b, integer c) = b == 2 * c;
*/

/*@
lemma calc_example_4: \forall integer a, b, c;
    is_five(a) && is_double(a, b) && is_minus_five(b, c) ==> is_equal(c, a);
*/

/*@
lemma calc_example_5: \forall integer a, b, c;
    is_five(a) && is_double(a, b) && is_minus_five(b, c) ==> is_double_c(b, c);
*/

int main() {
    int a;
    int b;
    int c;
    
    a = 5;
    //@ assert is_five(a);
    
    b = 2 * a;
    //@ assert is_double(a, b);
    
    c = b - 5;
    //@ assert is_minus_five(b, c);
    
    //@ assert is_equal(c, a);
    //@ assert is_double_c(b, c);
    
    return 0;
}
