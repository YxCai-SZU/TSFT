/*@
    requires 1 <= a <= b <= 20;
    ensures \result == a + b || \result == b - a;
    assigns \nothing;
*/
long func(long a, long b) {
    long result;
    int is_multiple_of_three;
    long temp_b;
    
    is_multiple_of_three = 0;
    temp_b = b;
    
    /*@
        loop invariant 1 <= a <= b <= 20;
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 3) {
        //@ assert temp_b >= 3;
        temp_b = temp_b - 3;
    }
    
    if (temp_b == 0) {
        //@ assert ((temp_b) % 3 == 0);
        is_multiple_of_three = 1;
    }
    
    if (is_multiple_of_three) {
        result = a + b;
        //@ assert result == a + b;
    } else {
        result = b - a;
        //@ assert result == b - a;
    }
    
    return result;
}
