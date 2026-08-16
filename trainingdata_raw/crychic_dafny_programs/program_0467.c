// Generated C + ACSL

/*@
  predicate sorted(int *a, integer len, integer low, integer high) =
    \forall integer j, k; low <= j && j < k && k < high ==> a[j] <= a[k];
*/

int select(int* a, int a_len, int i);

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void selection_sort(int* a, int a_len)
{
  int max;
  int i;
  i = (a_len - 1);
  max = i;
/*@
  loop invariant 0 <= i < a_len;
  loop invariant \forall integer k; i < k < a_len ==>
    (\forall integer m; k < m < a_len ==> a[k] <= a[m]);
  loop invariant \forall integer k; i < k < a_len ==>
    (\forall integer j; 0 <= j <= i ==> a[j] <= a[k]);
  loop invariant sorted(a, a_len, i+1, a_len);
  loop assigns i, max, a[0..a_len-1];
  loop variant i;
*/
  while ((i > 0))
    {
      max = select(a, a_len, i);
      /*@ assert 0 <= max <= i; */
      /*@ assert \forall integer x; 0 <= x <= i ==> a[x] <= a[max]; */
      /* unsupported stmt: a[i], a[max] := a[max], a[i]; */
      int temp = a[i];
      a[i] = a[max];
      a[max] = temp;
      /*@ assert \forall integer x; 0 <= x < i ==> a[x] <= a[i]; */
      /*@ assert \forall integer k; i < k < a_len ==> a[i] <= a[k]; */
      i = (i - 1);
    }
}

/*@
    requires 0 <= i < a_len;
    requires a_len > 0;
    requires a != \null;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result <= i;
    ensures \forall integer x; 0 <= x <= i ==> a[x] <= a[\result];
*/
int select(int* a, int a_len, int i)
{
  int j = i;
  int m = j;
  /*@ assert m >= 0 && m <= 2147483647; */
/*@
  loop invariant 0 <= j <= \at(i, LoopEntry);
  loop invariant 0 <= m <= \at(i, LoopEntry);
  loop invariant \forall integer x; j <= x <= \at(i, LoopEntry) ==> a[m] >= a[x];
  loop assigns j, m;
  loop variant j;
*/
  while ((j > 0))
    {
      j = (j - 1);
      if ((a[j] > a[m]))
      {
        m = j;
      }
    }
  return m;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int A[10] = {4, 8, 8, 3, 5, 10, 9, 9, 4, 7};
  selection_sort(A, 10);
}