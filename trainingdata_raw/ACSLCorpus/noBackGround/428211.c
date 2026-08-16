/*@
    requires x < 100;
    ensures \result == (x > 50);
    assigns \nothing;
*/
_Bool greater_than_threshold(unsigned int x) {
    unsigned int threshold = 50;
    //@ assert x < 100;
    return x > threshold;
}

/*@
    requires threshold < 100;
    ensures \result == (x > threshold);
    assigns \nothing;
*/
_Bool func_with_threshold(unsigned int x, unsigned int threshold) {
    //@ assert threshold < 100;
    return x > threshold;
}

int main() {
    unsigned int x = 70;
    _Bool result;
    
    result = greater_than_threshold(x);
    //@ assert result == 1;
    
    return 0;
}
