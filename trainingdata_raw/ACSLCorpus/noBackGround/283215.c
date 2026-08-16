/*@
requires ((x) >= 5);
ensures \result == 1;
*/
int example_function(int x) {
    int result;
    //@ assert x - 2 <= x + 3;
    result = 1;
    return result;
}

int main() {
    int x = 7;
    int y = 12;
    int res1;
    int res2;
    
    //@ assert ((x) >= 5);
    res1 = example_function(x);
    
    //@ assert ((y) >= 10);
    //@ assert y - 2 <= y + 3;
    res2 = 1;
    
    return 0;
}
