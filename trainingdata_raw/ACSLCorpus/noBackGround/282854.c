/*@
    requires (1 <= (x) <= 10000);
    ensures \result == (((x) - 1) / 1000 + 1);
*/
int func(int x) {
    int quotient = 0;
    int temp_x = x - 1;
    int divisor = 1000;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_x;
        loop invariant temp_x == x - 1 - quotient * divisor;
        loop invariant divisor == 1000;
        loop assigns temp_x, quotient;
        loop variant temp_x;
    */
    while (temp_x >= divisor) {
        //@ assert temp_x >= 1000;
        temp_x -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient == (x - 1) / 1000;
    return quotient + 1;
}

int main() {
    return 0;
}
