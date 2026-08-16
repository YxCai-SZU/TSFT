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
  }
  /*@ assert (ap <= bp && ap <= cp) ==> m == ap; */
  if (((bp <= ap) && (bp <= cp)))
  {
    m = bp;
  }
  /*@ assert (bp <= ap && bp <= cp) ==> m == bp; */
  if (((cp <= ap) && (cp <= bp)))
  {
    m = cp;
  }
  /*@ assert (cp <= ap && cp <= bp) ==> m == cp; */
  /*@ assert m == ap || m == bp || m == cp; */
  /*@ assert m >= 0; */
  /*@ assert (m != -1); */
  return m;  // Dafny implicit return
}