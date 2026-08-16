/*@
    requires x <= y;
    requires y <= x + 2;
    ensures \result == 0;
*/
int func(int x, int y) {
    //@ assert x <= y;
    //@ assert y <= x + 2;
    
    int result = 0;
    
    //@ assert x <= y;
    
    return result;
}

int main() {
    return 0;
}
