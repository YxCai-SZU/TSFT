// Generated C + ACSL

/*@
    requires x >= 0 && x <= 2147483640;
    assigns \nothing;
    ensures \result % 10 == 0;
    ensures \result >= 0 && \result <= 2147483640;
    ensures x % 10 == 0 ==> \result == x;
    ensures x % 10 >= 5 ==> \result == (x / 10 + 1) * 10;
    ensures x % 10 < 5 ==> \result == x / 10 * 10;
*/
int round10(int x)
{
  int result;
  if (((x % 10) == 0))
  {
    result = x;
    /*@ assert result >= 0 && result <= 2147483640; */
    /*@ assert result == x; */
  }
  else
  if (((x % 10) >= 5))
  {
    /*@ assert x / 10 >= 0 && x / 10 <= 214748364; */
    /*@ assert (x / 10 + 1) <= 214748364; */
    result = (((x / 10) + 1) * 10);
    /*@ assert result >= 0 && result <= 2147483640; */
  }
  else
  {
    /*@ assert x / 10 >= 0 && x / 10 <= 214748364; */
    result = ((x / 10) * 10);
    /*@ assert result >= 0 && result <= 2147483640; */
  }
  /*@ assert result >= 0 && result <= 2147483640; */
  return result;  // Dafny implicit return
}

/*@
    requires a >= 0 && a <= 715827880;
    requires b >= 0 && b <= 715827880;
    requires c >= 0 && c <= 715827880;
    assigns \nothing;
    ensures \result % 10 == 0;
    ensures \result >= 0;
*/
int round_sum(int a, int b, int c)
{
  int rounded_a = round10(a);
  /*@ assert rounded_a >= 0 && rounded_a <= 715827880; */
  int rounded_b = round10(b);
  /*@ assert rounded_b >= 0 && rounded_b <= 715827880; */
  int rounded_c = round10(c);
  /*@ assert rounded_c >= 0 && rounded_c <= 715827880; */
  /*@ assert rounded_a + rounded_b >= 0 && rounded_a + rounded_b <= 1431655760; */
  int result = ((rounded_a + rounded_b) + rounded_c);
  /*@ assert result >= 0 && result <= 2147483640; */
  return result;  // Dafny implicit return
}