// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == 1 <==> (n >= 2 && (\forall integer k; 2 <= k < n ==> n % k != 0));
    ensures \result == 0 <==> (n < 2 || (\exists integer k; 2 <= k < n && n % k == 0));
*/
int IsPrime(int n)
{
  if ((n < 2))
  {
    return 0;
  }
  int i = 2;
  int isPrime = 1;
  /*@ assert isPrime >= 0 && isPrime <= 2147483647; */
/*@
  loop invariant 2 <= i <= n;
  loop invariant isPrime == 1 ==> \forall integer k; 2 <= k < i ==> n % k != 0;
  loop invariant isPrime == 0 ==> \exists integer k; 2 <= k < i && n % k == 0;
  loop invariant isPrime == 0 || isPrime == 1;
  loop assigns i, isPrime;
  loop variant n - i;
*/
  while ((i < n))
    {
      if (((n % i) == 0))
      {
        isPrime = 0;
        break;;
      }
      i = (i + 1);
    }
  return isPrime;
}

/*@
    requires start <= end;
    requires start >= 0;
    assigns \nothing;
*/
void PrintPrimesInRange(int start, int end)
{
  int current = start;
/*@
  loop invariant start <= current <= end;
  loop invariant \at(start, LoopEntry) == start;
  loop invariant \at(end, LoopEntry) == end;
  loop assigns current;
  loop variant end - current;
*/
  while ((current < end))
    {
      int isPrime = IsPrime(current);
      if (isPrime)
      {
        /* unsupported stmt: print current, "\n"; */
      }
      current = (current + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  PrintPrimesInRange(2, 10);;
}
