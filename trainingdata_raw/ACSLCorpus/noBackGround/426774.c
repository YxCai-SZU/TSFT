/*@
  requires t > 0 && a > 0 && b > 0;
  ensures \result == t * (a + b);
*/
int func(int t, int a, int b) {
    //@ assert t > 0 && a > 0 && b > 0;
    //@ assert t * (a + b) == t * a + t * b;
    
    int result;
    result = t * (a + b);
    
    return result;
}

int main() {
    return 0;
}
