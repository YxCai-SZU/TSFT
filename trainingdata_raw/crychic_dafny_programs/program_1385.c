// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 1;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures \forall integer u, v; 0 <= u < v < a_len ==> a[u] <= a[v];
*/
void bubbleSort(int* a, int a_len)
{
  int i = 1;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer u, v; 0 <= u < v < i ==> a[u] <= a[v];
  loop assigns i, a[0..a_len-1];
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      int j = i;
      /*@ assert j >= 0 && j <= 2147483647; */
/*@
  loop invariant 0 <= j <= i;
  loop invariant \forall integer u, v; 0 <= u < v < j ==> a[u] <= a[v];
  loop invariant \forall integer u, v; j <= u < v < i + 1 ==> a[u] <= a[v];
  loop invariant \forall integer u, v; 0 <= u < j && j < v < i + 1 ==> a[u] <= a[v];
  loop assigns j, a[0..i];
  loop variant j;
*/
      while ((j > 0))
        {
          if ((a[(j - 1)] > a[j]))
          {
            int temp = a[(j - 1)];
            a[j] = temp;
            a[(j - 1)] = a[j];
          }
          j = (j - 1);
        }
      i = (i + 1);
    }
}
