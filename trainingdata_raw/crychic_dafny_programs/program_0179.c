// Generated C + ACSL

/*@
    requires a > 0;
    requires b > 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer d; 1 <= d <= a && 1 <= d <= b && a % d == 0 && b % d == 0 ==> \result >= d;
*/
int SumOfCommonDivisors(int a, int b)
{
  int sum = 0;
  /*@ assert sum >= 0 && sum <= 2147483647; */
  int i = 1;
/*@
  loop invariant 1 <= i <= a + 1;
  loop invariant 1 <= i <= b + 1;
  loop invariant sum >= 0;
  loop invariant \forall integer d; 1 <= d < i && a % d == 0 && b % d == 0 ==> sum >= d;
  loop assigns i, sum;
  loop variant (a < b ? a : b) - i + 1;
*/
  while (((i <= a) && (i <= b)))
    {
      if ((((a % i) == 0) && ((b % i) == 0)))
      {
        sum = (sum + i);
      }
      i = (i + 1);
    }
  return sum;  // Dafny implicit return
}
