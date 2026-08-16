/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> product(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int x;
    unsigned int y;
    unsigned int result;
    
    x = a;
    y = b;
    
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert product(x, y) <= 10000;
    
    result = x * y;
    return result;
}

int main(void) {
    return 0;
}
