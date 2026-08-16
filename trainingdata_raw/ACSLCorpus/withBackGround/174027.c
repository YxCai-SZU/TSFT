/*@
    predicate positive(integer x) = x > 0;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma product_comparison:
        \forall integer x; positive(x) ==> multiply(x, 5) >= multiply(x, 2);
*/

/*@
    requires x > 0;
    ensures \result >= x * 2;
*/
int func(int x) {
    int result;
    
    //@ assert x > 0;
    
    result = x * 5;
    
    //@ assert result >= x * 2;
    
    return result;
}

int main() {
    return 0;
}
