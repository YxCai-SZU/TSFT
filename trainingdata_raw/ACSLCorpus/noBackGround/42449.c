/*@
requires a > 0 && b > 0 && c > 0;
requires a + b <= 100 && b + c <= 100 && c + a <= 100;
ensures \result <= 300;
assigns \nothing;
*/
int main_func(int a, int b, int c) {
    int result;
    
    //@ assert a + b <= 100;
    result = a + b + c;
    
    //@ assert result <= 300;
    return result;
}

int main() {
    return 0;
}
