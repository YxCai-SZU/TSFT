/*@
requires 0 <= n <= 9;
ensures \result == 1 <==> ((n) == ((n) / 10) * 10 + ((n) % 10));
assigns \nothing;
*/
int is_palindrome_func(int n) {
    int result;
    
    //@ assert n >= 0 && n <= 9;
    result = (n == (n / 10) * 10 + (n % 10));
    
    //@ assert result == 1 <==> ((n) == ((n) / 10) * 10 + ((n) % 10));
    return result;
}

int main() {
    return 0;
}
