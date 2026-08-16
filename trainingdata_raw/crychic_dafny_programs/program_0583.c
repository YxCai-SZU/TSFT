// Generated C + ACSL

typedef struct {
  int x;
  int y;
} Point;

/*@
    assigns \nothing;
*/
void Main(void)
{
  Point c;
  Point j1;
  Point j2;
  c.x = 10;
  c.y = 20;
  j1.x = 20;
  j2.y = 10;
  /* unsupported stmt: print "c.x + c.y = ", c.x + c.y, "\n"; */
  /* unsupported stmt: print "j1.x + j2.y = ", j1.x + j2.y, "\n"; */
  /*@ assert ((c.x + c.y) == (j1.x + j2.y)); */
}