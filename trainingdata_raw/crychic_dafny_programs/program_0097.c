// Generated C + ACSL

/*@
    requires 100 <= n < 1000;
    assigns \nothing;
    ensures \result <==> (n == (n / 100) * (n / 100) * (n / 100) +
                                (n / 10 % 10) * (n / 10 % 10) * (n / 10 % 10) +
                                (n % 10) * (n % 10) * (n % 10));
*/
int IsArmstrong(int n)
{
  int a = (n / 100);
  int b = ((n / 10) % 10);
  int c = (n % 10);
  int result = (n == ((((a * a) * a) + ((b * b) * b)) + ((c * c) * c)));
  /*@ assert result >= 0 && result <= 2147483647; */
  return result;  // Dafny implicit return
}
