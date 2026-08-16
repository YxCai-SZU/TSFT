/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == (((g) * 10 + (b)) % 4 == 0);
*/
_Bool func(unsigned int r, unsigned int g, unsigned int b) {
    unsigned int sum;
    _Bool is_divisible;
    unsigned int temp_sum;
    
    //@ assert (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    sum = g * 10 + b;
    is_divisible = 0;
    temp_sum = sum;
    
    /*@
        loop invariant 1 <= r <= 9;
        loop invariant 1 <= g <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum == ((g) * 10 + (b));
        loop invariant (sum - temp_sum) % 4 == 0;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4) {
        //@ assert temp_sum >= 4;
        temp_sum -= 4;
        //@ assert (sum - temp_sum) % 4 == 0;
    }
    
    if (temp_sum == 0) {
        is_divisible = 1;
    }
    
    //@ assert is_divisible == (((g) * 10 + (b)) % 4 == 0);
    return is_divisible;
}
