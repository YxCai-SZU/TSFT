/*@
    requires \valid(result);
    requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= h <= 100 && h % 2 == 0;
    ensures *result == (a + b) * h / 2;
    assigns *result;
*/
void func(int a, int b, int h, int *result) {
    // Variable declarations at top of scope
    int sum;
    int product_val;
    int half;
    int temp;
    int local_result;
    
    // Precondition checks
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (h) <= 100 && (h) % 2 == 0);
    
    sum = a + b;
    //@ assert 1 <= sum <= 200;
    
    // Arithmetic safety
    //@ assert 1 * 1 <= (a + b) * h <= 200 * 100;
    product_val = sum * h;
    
    half = 2;
    local_result = 0;
    temp = product_val;
    
    /*@
        loop invariant 0 <= temp <= product_val;
        loop invariant local_result * 2 == product_val - temp;
        loop invariant 1 <= a <= 100 && 1 <= b <= 100 && 1 <= h <= 100;
        loop invariant 1 <= sum <= 200;
        loop assigns temp, local_result;
        loop variant temp;
    */
    while (temp >= half) {
        temp -= half;
        local_result += 1;
    }
    
    // Post-loop verification
    //@ assert temp < half;
    //@ assert local_result * 2 == product_val - temp;
    //@ assert product_val == (a + b) * h;
    //@ assert local_result == (a + b) * h / 2;
    
    *result = local_result;
}
