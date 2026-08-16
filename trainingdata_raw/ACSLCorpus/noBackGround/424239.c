/*@
requires ((x) + (y) >= 0) && ((x) + (y) < 0);
ensures \result == 0;
*/
int example(int x, int y) {
    int result = 0;
    
    //@ assert x + y >= 0;
    //@ assert x + y < 0;
    
    return result;
}

int main() {
    return 0;
}
