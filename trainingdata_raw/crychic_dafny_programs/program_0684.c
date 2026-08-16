// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result == 0 ==> p1 * c1 == p2 * c2;
    ensures \result == -1 ==> p1 * c1 < p2 * c2;
    ensures \result == 1 ==> p1 * c1 > p2 * c2;
    ensures \result == -1 || \result == 0 || \result == 1;
*/
int CompareProducts(int p1, int c1, int p2, int c2)
{
  int prod1 = (p1 * c1);
  int prod2 = (p2 * c2);
  int result;
  if (prod1 == prod2)
  {
    result = 0;
    /*@ assert result >= 0 && result <= 2147483647; */
  }
  else
  if (prod1 < prod2)
  {
    result = -1;
  }
  else
  {
    result = 1;
  }
  return result;
}

/*@
    requires \true;
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "Enter p1: "; */
  int p1 = 2.0;
  /* unsupported stmt: print "Enter c1: "; */
  int c1 = 3.0;
  /* unsupported stmt: print "Enter p2: "; */
  int p2 = 1.0;
  /* unsupported stmt: print "Enter c2: "; */
  int c2 = 5.0;
  int result = CompareProducts(p1, c1, p2, c2);
  if (result == 0)
  {
    /* unsupported stmt: print "O\n"; */
  }
  else
  if (result == -1)
  {
    /* unsupported stmt: print "-1\n"; */
  }
  else
  {
    /* unsupported stmt: print "1\n"; */
  }
}