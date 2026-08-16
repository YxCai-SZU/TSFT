/*@
    predicate is_double(integer a, integer b) = a == b * 2;
    predicate is_half(integer a, integer b) = a / 2 == b;
    
    lemma example_3: \forall integer a, b; is_double(a, b) ==> is_half(a, b);
*/

/*@
    requires is_double(a, b);
    ensures is_half(a, b);
*/
void example_3(int a, int b) {
    //@ assert is_double(a, b);
    //@ assert is_half(a, b);
}

int main() {
    return 0;
}
