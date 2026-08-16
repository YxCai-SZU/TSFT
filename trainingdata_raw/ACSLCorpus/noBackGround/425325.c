/*@
  requires 0 <= a && a < 10;
  requires 0 <= b && b < 10;
  ensures \result < 100;
  assigns \nothing;
*/
int func(int a, int b) {
    //@ assert a >= 0 && a < 10;
    //@ assert b >= 0 && b < 10;
    //@ assert a * b >= 0;
    //@ assert a * b < 100;
    return a * b;
}

/*@
  requires 0 <= a && a < 10;
  requires 0 <= b && b < 10;
  ensures \result < 100;
  assigns \nothing;
*/
int func2(int a, int b) {
    //@ assert a >= 0 && a < 10;
    //@ assert b >= 0 && b < 10;
    //@ assert a * b >= 0;
    //@ assert a * b < 100;
    return a * b;
}

int main() {
    return 0;
}
