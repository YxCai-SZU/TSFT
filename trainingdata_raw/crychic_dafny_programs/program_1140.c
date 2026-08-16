// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
    ensures n == 0 ==> \result == 0;
    ensures n > 0 ==> \result == (n / 7) * 28 + (n / 7) * ((n / 7) - 1) * 7 / 2 +
                                  (n % 7) * (2 * ((n / 7) + 1) + ((n % 7) - 1)) / 2;
*/
int TotalMoney(int n)
{
  int x = (n / 7);
  int total = (((7 * x) * (x + 7)) / 2);
  /*@ assert total >= 0 && total <= 2147483647; */
  /*@ assert total == 7 * x * (x + 7) / 2; */
  /*@ assert total == x * 28 + x * (x - 1) * 7 / 2; */
  int r = (n % 7);
  /*@ assert r == n % 7; */
  /*@ assert 0 <= r < 7; */
  int s = (x + 1);
  /*@ assert s == x + 1; */
  int i = 0;
/*@
  loop invariant 0 <= i <= r;
  loop invariant total == 7 * x * (x + 7) / 2 + i * (2 * (x + 1) + (i - 1)) / 2;
  loop invariant total == x * 28 + x * (x - 1) * 7 / 2 + i * (2 * (x + 1) + (i - 1)) / 2;
  loop invariant s == x + 1;
  loop invariant r == n % 7;
  loop invariant x == n / 7;
  loop assigns i, total;
  loop variant r - i;
*/
  while ((i < r))
    {
      total = (total + (s + i));
      i = (i + 1);
    }
  /*@ assert i == r; */
  /*@ assert r == n % 7; */
  /*@ assert x == n / 7; */
  /*@ assert total == x * 28 + x * (x - 1) * 7 / 2 + r * (2 * (x + 1) + (r - 1)) / 2; */
  /*@ assert n > 0 ==> total == (n / 7) * 28 + (n / 7) * ((n / 7) - 1) * 7 / 2 +
                                (n % 7) * (2 * ((n / 7) + 1) + ((n % 7) - 1)) / 2; */
  return total;  // Dafny implicit return
}