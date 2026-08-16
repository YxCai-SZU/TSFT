/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds: 
        \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) <= 100 * 100;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
int func(int a, int b) {
    int dummy = 0;
    
    /*@
        loop invariant 0 <= dummy <= 20;
        loop invariant valid_range(a) && valid_range(b);
        loop assigns dummy;
        loop variant 20 - dummy;
    */
    while (dummy < 20) {
        dummy++;
    }
    
    //@ assert 1 <= product(a, b) <= 100 * 100;
    
    return a * b;
}

int main() {
    return 0;
}
