/*@
    requires 1 <= a <= 500;
    requires 1 <= b <= 500;
    requires 1 <= c <= 1000;
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
_Bool func(unsigned long long a, unsigned long long b, unsigned long long c) {
    _Bool is_enough;
    unsigned long long sum;
    
    is_enough = 0;
    sum = a + b;
    
    if (sum >= c) {
        is_enough = 1;
    }
    
    //@ assert is_enough == (sum >= c);
    
    return is_enough;
}
