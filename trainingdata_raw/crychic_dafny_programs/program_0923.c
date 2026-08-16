// Generated C + ACSL

/*@
    requires n >= 1;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 <==> (n > 1 && (\forall integer k; 2 <= k < n ==> n % k != 0));
    ensures n == 1 ==> \result == 0;
    ensures n == 2 ==> \result == 1;
*/
int IsPrime(int n)
{
  if ((n == 1))
  {
    return 0;
  }
  if ((n == 2))
  {
    return 1;
  }
  int divisor = 2;
  /*@ assert n >= 3; */
  /*@ assert divisor == 2; */
/*@
  loop invariant 2 <= divisor <= n;
  loop invariant \forall integer k; 2 <= k < divisor ==> n % k != 0;
  loop invariant divisor >= 2;
  loop assigns divisor;
  loop variant n - divisor;
*/
  while ((divisor < n))
    {
      /*@ assert 2 <= divisor < n; */
      /*@ assert \forall integer k; 2 <= k < divisor ==> n % k != 0; */
      if (((n % divisor) == 0))
      {
        /*@ assert n % divisor == 0; */
        /*@ assert 2 <= divisor < n; */
        return 0;
      }
      /*@ assert n % divisor != 0; */
      divisor = (divisor + 1);
      /*@ assert \forall integer k; 2 <= k < divisor ==> n % k != 0; */
    }
  /*@ assert divisor == n; */
  /*@ assert \forall integer k; 2 <= k < n ==> n % k != 0; */
  return 1;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int number = 17;
  int result = IsPrime(number);
  if (result)
  {
    /* unsupported stmt: print "It is a prime number.\n"; */
  }
  else
  {
    /* unsupported stmt: print "It is not a prime number.\n"; */
  }
}