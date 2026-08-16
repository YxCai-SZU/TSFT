/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 3142 * r / 1000;
*/
int func(int r) {
    int pi = 3142;
    int circumference = 0;
    int temp = 2 * pi * r;
    int divisor = 1000;
    
    //@ ghost int original = 2 * pi * r;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant (0 <= (circumference));
        loop invariant (0 <= (temp));
        loop invariant temp + circumference * divisor == original;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp + circumference * divisor == original;
        circumference += 1;
        temp -= divisor;
        //@ assert temp + circumference * divisor == original;
    }
    
    //@ assert temp + circumference * divisor == original;
    //@ assert temp < divisor;
    
    return circumference;
}

int main() {
    return 0;
}
