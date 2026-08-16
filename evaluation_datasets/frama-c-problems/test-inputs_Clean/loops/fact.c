/*@
  axiomatic Factorial {
  logic integer fact(integer n);

 

  axiom case_n:
    \forall integer n;
    n >= 1 ==> fact(n) == n*fact(n-1);
  axiom case_0:
    fact(0) == 1;
  }
*/

int factorial(int n) {
  int i = 1;
  int f = 1;

  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}

void test() {

  int f1 = factorial(0);
  //@ assert f1 == 1;

  int f2 = factorial(3);
  //@ assert f2 == 6;

  int f3 = factorial(5);
  //@ assert f3 == 120;
}
