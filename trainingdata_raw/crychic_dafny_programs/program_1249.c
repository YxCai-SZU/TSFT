// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int e = 9999;
/*@
  loop invariant e >= 0;
  loop assigns e;
  loop variant e;
*/
  while ((e > 0))
    {
      /* unsupported stmt: print "e"; */
      e = (e - 1);
    }
}
