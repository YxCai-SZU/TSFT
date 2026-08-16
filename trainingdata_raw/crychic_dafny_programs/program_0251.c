// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \exists integer k; 0 <= k < a_len && \result == a[k];
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= \result;
*/
int FindMax(int* a, int a_len)
{
  int max = a[0];
  /*@ assert max == a[0]; */
  /*@ assert \exists integer k; 0 <= k < 1 && max == a[k]; */
  int i = 1;
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max;
  loop invariant \exists integer k; 0 <= k < i && max == a[k];
  loop invariant \exists integer k; 0 <= k < a_len && max == a[k];
  loop assigns i, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] > max))
      {
        max = a[i];
        /*@ assert max == a[i]; */
        /*@ assert \exists integer k; 0 <= k < a_len && max == a[k]; */
      }
      /*@ assert \forall integer k; 0 <= k <= i ==> a[k] <= max; */
      i = (i + 1);
    }
  /*@ assert i == a_len; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] <= max; */
  /*@ assert \exists integer k; 0 <= k < a_len && max == a[k]; */
  return max;  // Dafny implicit return
}