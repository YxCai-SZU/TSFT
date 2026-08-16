// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
*/
void Main(void)
{
  /* unsupported stmt: print "1 = ", (x => x)(1), "\n"; */
  /* unsupported stmt: print "3 = ", (x => y => x + y)(1)(2), "\n"; */
  /* unsupported stmt: print "3 = ", ((x, y) => y + x)(1, 2), "\n"; */
  /* unsupported stmt: print "0 = ", (() => 0)(), "\n"; */
  int y = 1;
  int f = 0;
  /* unsupported stmt: print "3 = ", f(2), "\n"; */
  /* unsupported stmt: print "4 = ", f(3), "\n"; */
  y = 2;
  /* unsupported stmt: print "3 = ", f(2), "\n"; */
  /* unsupported stmt: print "4 = ", f(3), "\n"; */
  int z = 0;
  f = 0;
  /* unsupported stmt: print "3 = ", f(2), "\n"; */
  /* unsupported stmt: print "4 = ", f(3), "\n"; */
  /* unsupported stmt: z.val = 2; */
  /* unsupported stmt: print "4 = ", f(2), "\n"; */
  /* unsupported stmt: print "5 = ", f(3), "\n"; */
  f = 0;
  y = 10;
/*@
  loop invariant 0 <= y <= \at(y, LoopEntry);
  loop assigns f, y;
  loop variant y;
*/
  while ((y > 0))
    {
      f = 0;
      y = (y - 1);
    }
  /* unsupported stmt: print "55 = ", f(0), "\n"; */
  /* unsupported stmt: print "0 = ", (x => var y := x; y)(0), "\n"; */
  /* unsupported stmt: print "1 = ", (y => x => var y := x; y)(0)(1), "\n"; */
}