/*@
    requires (1 <= (r) && (r) <= 100);
    ensures ((\result) == (r) * 2 * 3);
    assigns \nothing;
*/
int func(int r) {
    int pi;
    int product;
    
    pi = 3;
    
    //@ assert pi == 3;
    
    product = r * 2 * pi;
    
    //@ assert product == r * 2 * 3;
    
    return product;
}
