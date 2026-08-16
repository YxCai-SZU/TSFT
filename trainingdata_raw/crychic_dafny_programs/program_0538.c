// Generated C + ACSL

typedef struct {
  int x;
} ClassC;

void UnusedLabel(void);
void LabelUsedInGhostCode(ClassC* c);

/*@
    assigns \nothing;
*/
void Main(void)
{
  UnusedLabel();
  ClassC c;
  c.x = 4;
  LabelUsedInGhostCode(&c);
  /* unsupported stmt: print c.x, "\n"; */
}

/*@
    assigns \nothing;
*/
void UnusedLabel(void)
{
  {
  }
}

/*@
    assigns \nothing;
*/
void LabelUsedInGhostCode(ClassC* c)
{
  int x = 0;
  x = x + 2;
  /*@ assert x >= 0 && x <= 2147483647; */
  A:;
  x = (x + 1);
  B:;
  x = (x + 3);
  /*@ assert (x == 6); */
  /*@ assert (x == \at(x, A) + 4); */
  /*@ assert (\at(x, B) + x == 9); */
}