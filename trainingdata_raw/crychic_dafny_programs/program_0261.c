// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
*/
void Main(void)
{
  int x = (2 + 1);
  int z = (3 + (3 * x));
  if ((x == x))
  {
    int x = 5;
    x = (x + 1);
  }
  /*@ assert (z == (4 * x)); */
}
