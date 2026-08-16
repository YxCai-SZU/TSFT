/*@
predicate positive(integer x) = x > 0;
predicate sum_bounded(integer a, integer b, integer c, integer d) = 
    a + b + c + d <= 10000;

lemma distributive_add_lemma: 
    \forall integer a, b, c; a * (b + c) == a * b + a * c;

lemma arithmetic_equality: 
    \forall integer a, b, c, d;
        positive(a) && positive(b) && positive(c) && positive(d) && 
        sum_bounded(a, b, c, d) ==> 
        a * (b + c) * d == a * b * d + a * c * d;
*/

/*@
    requires positive(a) && positive(b) && positive(c) && positive(d);
    requires sum_bounded(a, b, c, d);
    ensures \result == a * b * d + a * c * d;
*/
int nonlinear_arithmetic_example_5(int a, int b, int c, int d) {
    //@ assert positive(a);
    //@ assert positive(b);
    //@ assert positive(c);
    //@ assert positive(d);
    //@ assert sum_bounded(a, b, c, d);
    
    int result = a * (b + c) * d;
    
    //@ assert result == a * b * d + a * c * d;
    return result;
}

int main() {
    return 0;
}
