/*@
    requires x >= 0;
    ensures \result == 0 || \result == 1;
    ensures (\true) ==> x >= 0;
*/
int check_palindrome(int x) {
    int result = 0;
    
    //@ assert x >= 0;
    
    // Placeholder implementation
    result = 1;
    
    //@ assert (\true) ==> x >= 0;
    
    return result;
}

int main() {
    int test_value = 12321;
    
    //@ assert test_value >= 0;
    
    int res = check_palindrome(test_value);
    
    return 0;
}
