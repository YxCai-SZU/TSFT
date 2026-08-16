// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == a || \result == b || \result == c ||
            \result == -a || \result == -b || \result == -c;
    ensures \result <= a || \result <= -a;
    ensures \result <= b || \result <= -b;
    ensures \result <= c || \result <= -c;
*/
int Min(int a, int b, int c)
{
  int ap;
  int bp;
  int cp;
  if ((a >= 0))
  {
    ap = a;
  }
  else
  {
    ap = -a;
  }
  if ((b >= 0))
  {
    bp = b;
  }
  else
  {
    bp = -b;
  }
  if ((c >= 0))
  {
    cp = c;
  }
  else
  {
    cp = -c;
  }
  /*@ assert (((ap >= 0) && (bp >= 0)) && (cp >= 0)); */
  int m = -1;
  if (((ap <= bp) && (ap <= cp)))
  {
    m = ap;
    /*@ assert m == ap && m >= 0; */
  }
  if (((bp <= ap) && (bp <= cp)))
  {
    m = bp;
    /*@ assert m == bp && m >= 0; */
  }
  if (((cp <= ap) && (cp <= bp)))
  {
    m = cp;
    /*@ assert m == cp && m >= 0; */
  }
  /*@ assert (ap <= bp && ap <= cp) || (bp <= ap && bp <= cp) || (cp <= ap && cp <= bp); */
  /*@ assert (m != -1); */
  /*@ assert m >= 0; */
  /*@ assert m == ap || m == bp || m == cp; */
  /*@ assert m <= ap && m <= bp && m <= cp; */
  return m;  // Dafny implicit return
}