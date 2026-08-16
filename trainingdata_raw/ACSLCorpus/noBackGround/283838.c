/*@
    requires a > 0 && b > 0;
    ensures \result == a * a + b * b;
*/
int calculate_sum_of_squares(int a, int b) {
    int result;
    
    //@ assert ((a) > 0) && ((b) > 0);
    result = a * a + b * b;
    
    //@ assert result == a * a + b * b;
    return result;
}

int main() {
    int x = 3;
    int y = 4;
    int sum;
    
    //@ assert ((x) > 0) && ((y) > 0);
    sum = calculate_sum_of_squares(x, y);
    
    //@ assert sum == x * x + y * y;
    return 0;
}
