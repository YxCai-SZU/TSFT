// Generated C + ACSL

/*@
    requires a_Length0 >= 0;
    requires a_Length1 >= 0;
    requires a_Length0 == 0 || a_Length1 == 0 || (a != \null && \valid_read(a + (0 .. a_Length0 - 1)) && \forall integer i; 0 <= i < a_Length0 ==> a[i] != \null && \valid_read(a[i] + (0 .. a_Length1 - 1)));
    assigns \nothing;
*/
void printMatrix(int** a, int a_Length0, int a_Length1)
{
  int v = 0;
/*@
  loop invariant 0 <= v <= a_Length0;
  loop invariant \at(v, LoopEntry) <= v;
  loop assigns v;
  loop variant a_Length0 - v;
*/
  while ((v < a_Length0))
    {
      int y = 0;
      /* unsupported stmt: print "\n"; */
/*@
  loop invariant 0 <= y <= a_Length1;
  loop invariant \at(v, LoopEntry) == v;
  loop assigns y;
  loop variant a_Length1 - y;
*/
      while ((y < a_Length1))
        {
          /* unsupported stmt: print a[v, y]; */
          /* unsupported stmt: print "\t"; */
          y = (y + 1);
        }
      v = (v + 1);
    }
  /* unsupported stmt: print "\n"; */
}

/*@
    requires a_len >= 0;
    requires a_len == 0 || (a != \null && \valid_read(a + (0 .. a_len-1)));
    assigns \nothing;
*/
void printArray(int* a, int a_len)
{
  int v = 0;
/*@
  loop invariant 0 <= v <= a_len;
  loop invariant \at(v, LoopEntry) <= v;
  loop assigns v;
  loop variant a_len - v;
*/
  while ((v < a_len))
    {
      /* unsupported stmt: print a[v]; */
      /* unsupported stmt: print "\t"; */
      v = (v + 1);
    }
  /* unsupported stmt: print "\n"; */
}