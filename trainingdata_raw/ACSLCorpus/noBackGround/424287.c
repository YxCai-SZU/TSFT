/*@
    requires x >= 0;
    ensures \result <= x + 5;
    assigns \nothing;
*/
int calc_example(int x) {
    //@ assert x >= 0;
    int result;
    
    //@ ghost int step1 = x + 3;
    //@ assert step1 <= x + 5;
    
    //@ ghost int step2 = step1 + 2;
    //@ assert step2 <= x + 5;
    
    result = x + 5;
    //@ assert result <= x + 5;
    
    return result;
}

/*@
    requires x % 2 == 0;
    ensures ((x) % 2 == 0);
    assigns \nothing;
*/
void check_even(int x) {
    //@ assert x % 2 == 0;
}

/*@
    assigns \nothing;
*/
int main() {
    int x = 10;
    int y;
    
    y = calc_example(x);
    //@ assert x % 2 == 0;
    check_even(x);
    
    return 0;
}
