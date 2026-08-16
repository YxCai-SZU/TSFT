/*@
    requires (1 <= (a) && (a) <= 16 &&
        1 <= (b) && (b) <= 16 &&
        (a) + (b) <= 32);
    ensures \result == (((a) * (b)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int ans;
    
    //@ assert 1 <= a && a <= 16;
    //@ assert 1 <= b && b <= 16;
    //@ assert a * b <= 256;
    
    ans = (a * b) / 2;
    return ans;
}
