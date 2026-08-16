// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void Partition(int* a, int a_len)
{
  int i = 0;
  int j = a_len;
  int k = a_len;
/*@
  loop invariant 0 <= i <= j <= k <= a_len;
  loop invariant \forall integer x; 0 <= x < i ==> a[x] < 0;
  loop invariant \forall integer x; j <= x < k ==> a[x] == 0;
  loop invariant \forall integer x; k <= x < a_len ==> a[x] > 0;
  loop invariant i <= j <= \at(j, LoopEntry);
  loop invariant \at(k, LoopEntry) >= k;
  loop assigns i, j, k, a[0..a_len-1];
  loop variant j - i;
*/
  while ((i < j))
    {
      if ((a[i] < 0))
      {
        i = (i + 1);
      }
      else
      if ((a[i] == 0))
      {
        int current = a[i];
        a[i] = a[(j - 1)];
        a[(j - 1)] = current;
        j = (j - 1);
      }
      else
      {
        /*@ assert (a[i] > 0); */
        int current = a[i];
        a[i] = a[(j - 1)];
        a[(j - 1)] = a[(k - 1)];
        a[(k - 1)] = current;
        j = (j - 1);
        k = (k - 1);
      }
    }
  // TODO multiple returns
  return;
}