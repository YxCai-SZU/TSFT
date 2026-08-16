// Generated C + ACSL

/*@
    requires a != \null;
    requires 0 <= i <= j < a_len;
    requires \valid(a + (0 .. a_len-1));
    assigns a[i], a[j];
    ensures a[i] == \old(a[j]);
    ensures a[j] == \old(a[i]);
    ensures \forall integer k; 0 <= k < a_len && k != i && k != j ==> a[k] == \old(a[k]);
*/
void swap(int* a, int a_len, int i, int j)
{
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

/*@
    requires a != \null;
    requires a_len > 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
    ensures 0 <= \result <= a_len;
    ensures \forall integer j; 0 <= j < \result ==> a[j] != 0;
    ensures \forall integer j; \result <= j < a_len ==> a[j] == 0;
*/
int moveZero(int* a, int a_len)
{
  int first0 = 0;
  /*@ assert first0 >= 0 && first0 <= 2147483647; */
  int cur = 0;
/*@
  loop invariant 0 <= first0 <= cur <= a_len;
  loop invariant \forall integer j; 0 <= j < first0 ==> a[j] != 0;
  loop invariant \forall integer j; first0 <= j < cur ==> a[j] == 0;
  loop invariant \forall integer j; 0 <= j < a_len ==>
    (\exists integer k; 0 <= k < a_len && a[j] == \at(a[k], LoopEntry));
  loop invariant \forall integer j; 0 <= j < a_len ==>
    (\exists integer k; 0 <= k < a_len && \at(a[j], LoopEntry) == a[k]);
  loop assigns cur, first0, a[0..a_len-1];
  loop variant a_len - cur;
*/
  while ((cur < a_len))
    {
      if ((a[cur] != 0))
      {
        swap(a, a_len, first0, cur);;
        first0 = (first0 + 1);
      }
      cur = (cur + 1);
    }
  return first0;
}