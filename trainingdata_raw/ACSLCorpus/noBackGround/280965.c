/*@
    requires 1 <= a <= 500;
    requires 1 <= b <= 500;
    requires 1 <= c <= 1000;
    ensures \result == (a + b >= c || a >= c || b >= c);
    assigns \nothing;
*/
int func(long a, long b, long c)
{
    long original_a = a;
    long original_b = b;
    long original_c = c;
    int result = 0;
    
    //@ assert original_a == a && original_b == b && original_c == c;
    
    if (a + b >= c) {
        result = 1;
    } else if (a >= c) {
        result = 1;
    } else if (b >= c) {
        result = 1;
    }
    
    //@ assert result == (original_a + original_b >= original_c || original_a >= original_c || original_b >= original_c);
    
    return result;
}
