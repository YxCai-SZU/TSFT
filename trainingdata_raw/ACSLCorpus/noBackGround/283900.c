/*@
  requires a < 0 && b < 0 && c < 0;
  requires a + 1 < b;
  requires b + 1 < c;
  ensures \result == 0;
*/
int func(int a, int b, int c) {
    // Variable declarations at scope top
    int result = 0;
    
    //@ assert a < b + 1;
    //@ assert b < c + 1;
    //@ assert a + 1 < c + 1;
    //@ assert a < c;
    
    return result;
}

int main() {
    return 0;
}
