/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * 314159 / 100000);
    assigns \nothing;
*/
long func(long r) {
    long precision_factor;
    long pi;
    long ans;
    long temp;
    long divisor;
    
    precision_factor = 100000;
    pi = 314159;
    ans = 0;
    temp = 2 * r * pi;
    divisor = precision_factor;
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (divisor) == 100000 &&
        (pi) == 314159 &&
        (ans) >= 0 &&
        (temp) >= 0 &&
        (temp) + (ans) * (divisor) == 2 * (r) * (pi));
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        ans += 1;
    }
    
    //@ assert ans == (2 * (r) * 314159 / 100000);
    return ans;
}

int main() {
    return 0;
}
