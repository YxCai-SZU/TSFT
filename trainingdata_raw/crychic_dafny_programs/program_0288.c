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
  loop invariant \forall integer j; cur <= j < a_len ==> a[j] == \at(a[j], LoopEntry);
  loop invariant \forall integer j; 0 <= j < a_len ==>
                   (a[j] == 0 ==> \at(a[j], LoopEntry) == 0 || \at(a[j], LoopEntry) != 0);
  loop invariant \forall integer j; 0 <= j < a_len ==>
                   (a[j] != 0 ==> \at(a[j], LoopEntry) == 0 || \at(a[j], LoopEntry) != 0);
  loop invariant \forall integer j; cur <= j < a_len ==> 
                   (a[j] == 0 <==> \at(a[j], LoopEntry) == 0);
  loop invariant \forall integer j; cur <= j < a_len ==> 
                   (a[j] != 0 <==> \at(a[j], LoopEntry) != 0);
  loop assigns cur, first0, a[0..a_len-1];
  loop variant a_len - cur;
*/
  while ((cur < a_len))
    {
      /*@ assert 0 <= first0 <= cur < a_len; */
      /*@ assert \forall integer j; 0 <= j < first0 ==> a[j] != 0; */
      /*@ assert \forall integer j; first0 <= j < cur ==> a[j] == 0; */
      if ((a[cur] != 0))
      {
        /*@ assert a[cur] != 0; */
        /*@ assert 0 <= first0 <= cur < a_len; */
        swap(a, a_len, first0, cur);
        /*@ assert a[first0] != 0; */
        /*@ assert \forall integer j; 0 <= j < first0 ==> a[j] != 0; */
        first0 = (first0 + 1);
        /*@ assert \forall integer j; 0 <= j < first0 ==> a[j] != 0; */
      }
      /*@ assert first0 <= cur + 1; */
      cur = (cur + 1);
      /*@ assert 0 <= first0 <= cur <= a_len; */
    }
  /*@ assert cur == a_len; */
  /*@ assert 0 <= first0 <= a_len; */
  /*@ assert \forall integer j; 0 <= j < first0 ==> a[j] != 0; */
  /*@ assert \forall integer j; first0 <= j < a_len ==> a[j] == 0; */
  return first0;
}