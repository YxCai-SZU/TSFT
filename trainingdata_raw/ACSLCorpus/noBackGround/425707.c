/*@
    requires ((a) > 0) && ((a) <= 1000);
    requires ((b) > 0) && ((b) <= 1000);
    ensures \result == (((a) * (b)) % 2 != 0);
*/
_Bool func(unsigned int a, unsigned int b) {
    unsigned int product;
    _Bool is_odd;
    unsigned int temp;
    
    //@ assert ((a) * (b)) <= 1000000;
    
    product = a * b;
    is_odd = 0;
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant ((a) > 0) && ((a) <= 1000);
        loop invariant ((b) > 0) && ((b) <= 1000);
        loop invariant product == a * b;
        loop assigns temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }
    
    if (temp == 1) {
        is_odd = 1;
    }
    
    return is_odd;
}
