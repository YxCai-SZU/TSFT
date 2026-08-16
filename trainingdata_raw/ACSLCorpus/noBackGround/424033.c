/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  ensures \result <= 10000;
*/
int nonlinear_arithmetic_example_10(int a, int b) {
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    //@ assert a * b <= 10000;
    return a * b;
}
