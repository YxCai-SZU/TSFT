/*@
    requires x >= 2 && y >= 2 && x <= y;
    ensures \result == 1;
    assigns \nothing;
*/
int check_greater_than_threshold(int x, int y) {
    int result;
    
    //@ assert x >= 2 && y >= 2 && x <= y;
    //@ assert ((x) + 2) <= ((y) + 2);
    
    result = (x + 2) <= (y + 2);
    //@ assert result == 1;
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    int x;
    int y;
    int verification_result;
    
    x = 3;
    y = 5;
    verification_result = check_greater_than_threshold(x, y);
    
    return 0;
}
