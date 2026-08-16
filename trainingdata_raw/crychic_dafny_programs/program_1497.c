// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer j; 0 <= j < a_len ==> \result >= a[j];
    ensures a_len > 0 ==> \exists integer j; 0 <= j < a_len && \result == a[j];
*/
int max(int *a, int a_len)
{
  int max;
  if ((a_len == 0))
  {
    max = 0;
    /*@ assert max >= 0 && max <= 2147483647; */
  }
  else
  {
    max = a[0];
    int i = 1;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> max >= a[j];
  loop invariant \exists integer j; 0 <= j < i && max == a[j];
  loop assigns i, max;
  loop variant a_len - i;
*/
    while ((i < a_len))
      {
        if ((a[i] > max))
        {
          max = a[i];
        }
        i = (i + 1);
      }
  }
  return max;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int a[5];
  a[0] = 12;
  a[1] = 3;
  a[2] = 44;
  a[3] = 44;
  a[4] = 1;
  int b = max(a, 5);
  /* unsupported stmt: print "Index: ", b; */
}