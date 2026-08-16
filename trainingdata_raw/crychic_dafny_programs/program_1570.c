// Generated C + ACSL

/*@ logic integer Fib(integer n) = 
  @   (n < 2) ? n : Fib(n-1) + Fib(n-2);
  @*/

/*@ requires n >= 0;
  @ requires n < 47;
  @ decreases n;
  @ ensures \result == Fib(n);
  @ ensures \result >= 0;
  @*/
int Fib(int n)
{
  return ((n < 2)) ? (n) : ((Fib((n - 2)) + Fib((n - 1))));
}

/*@ requires n >= 0;
  @ requires n < 47;
  @ ensures \result == Fib(n);
  @ ensures \result >= 0;
  @*/
int Fibonacci(int n)
{
  int aux = 0;
  int f;
  if ((n < 2))
  {
    f = n;
    /*@ assert f == Fib(n); */
    /*@ assert f >= 0 && f <= 2147483647; */
  }
  else
  {
    int i = 0;
    f = 1;
    /*@ assert f == Fib(1); */
    /*@ assert aux == Fib(0); */
    /*@ assert i == 0; */
/*@
  loop invariant 0 <= i <= n - 1;
  loop invariant f == Fib(i + 1);
  loop invariant aux == Fib(i);
  loop invariant f >= 0;
  loop invariant aux >= 0;
  loop invariant i < n - 1 ==> f + aux >= 0;
  loop assigns i, f, aux;
  loop variant (n - 2) - i;
*/
    while ((i <= (n - 2)))
      {
        int old_f = f;
        int old_aux = aux;
        /*@ assert old_f == Fib(i + 1); */
        /*@ assert old_aux == Fib(i); */
        f = (f + aux);
        /*@ assert f == old_f + old_aux; */
        /*@ assert f == Fib(i + 1) + Fib(i); */
        /*@ assert f == Fib(i + 2); */
        aux = (f - aux);
        /*@ assert aux == f - old_aux; */
        /*@ assert aux == old_f; */
        /*@ assert aux == Fib(i + 1); */
        i = (i + 1);
        /*@ assert i >= 1; */
        /*@ assert aux == Fib(i); */
        /*@ assert f == Fib(i + 1); */
      }
    /*@ assert i == n - 1; */
    /*@ assert f == Fib(n); */
  }
  return f;
}