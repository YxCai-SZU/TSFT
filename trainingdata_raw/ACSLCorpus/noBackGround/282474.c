/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3);
    ensures \result == (a * b % 2 != 0);
*/
_Bool func(unsigned long long a, unsigned long long b) {
    unsigned long long product;
    _Bool ans;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    
    product = a * b;
    
    //@ assert 1 <= product <= 9;
    
    if (product % 2 != 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans == (product % 2 != 0);
    
    return ans;
}
