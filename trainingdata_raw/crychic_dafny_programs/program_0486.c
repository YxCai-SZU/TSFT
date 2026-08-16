// Generated C + ACSL

/*@
    requires a >= 0;
    assigns \nothing;
    ensures \result == a * a;
*/
int Carre(int a)
{
  int i = 0;
  int c = 0;
  /*@ assert c >= 0 && c <= 2147483647; */
/*@
  loop invariant 0 <= i <= a;
  loop invariant c == i * i;
  loop assigns i, c;
  loop variant a - i;
*/
  while ((i != a))
    {
      c = ((c + (2 * i)) + 1);
      i = (i + 1);
    }
  return c;  // Dafny implicit return
}
