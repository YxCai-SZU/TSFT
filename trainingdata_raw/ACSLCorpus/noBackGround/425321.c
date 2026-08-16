/*@
    requires (1 <= (x) && (x) <= 10);
    ensures \result == x * 2;
    ensures \result >= 2;
    ensures \result <= 20;
*/
int calculate(int x) {
    //@ assert (1 <= (x) && (x) <= 10);
    
    int result;
    result = x * 2;
    
    //@ assert result == 2 * x;
    //@ assert result >= 2;
    //@ assert result <= 20;
    
    return result;
}

int main() {
    int x = 5;
    int res = calculate(x);
    return 0;
}
