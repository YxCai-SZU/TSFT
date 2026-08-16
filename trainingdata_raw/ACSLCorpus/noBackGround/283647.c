/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    ensures ((\result) == ((a) * 4 >= (b)));
    assigns \nothing;
*/
int func(unsigned long long a, unsigned long long b) {
    // Variable declarations at top of scope
    unsigned long long product;
    int result;
    
    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    
    product = a * 4;
    
    //@ assert 0 <= product <= 400;
    //@ assert product == a * 4;
    
    result = (product >= b) ? 1 : 0;
    
    //@ assert result == (a * 4 >= b);
    
    return result;
}
