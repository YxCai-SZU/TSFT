// Generated C + ACSL

/*@
    requires a_len >= 1;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures 0 <= \result < a_len;
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= a[\result];
*/
int FindMax(int* a, int a_len)
{
  int i = 1;
  int idx = 0;
  /*@ assert idx >= 0 && idx <= 2147483647; */
  int max = a[idx];
  /*@ assert max == a[0]; */
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant 0 <= idx < a_len;
  loop invariant idx < i;
  loop invariant max == a[idx];
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[idx];
  loop assigns i, idx, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] >= max))
      {
        idx = i;
        max = a[idx];
        /*@ assert max == a[i]; */
        /*@ assert idx == i; */
      }
      /*@ assert a[i] >= max ==> max == a[i]; */
      /*@ assert a[i] < max ==> max == \at(max, LoopCurrent); */
      i = (i + 1);
    }
  /*@ assert i == a_len; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] <= max; */
  /*@ assert max == a[idx]; */
  return idx;
}

/*@
    requires a != \null;
    requires a_len >= 1;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer k; 0 <= k < a_len ==> a[k] <= \result;
    ensures \exists integer j; 0 <= j < a_len && a[j] == \result;
*/
int FindMaxVal(int* a, int a_len)
{
  int i = 0;
  int val = a[0];
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] <= val;
  loop invariant \exists integer j; 0 <= j < a_len && a[j] == val;
  loop invariant i == 0 ==> val == a[0];
  loop invariant i > 0 ==> (\exists integer k; 0 <= k < i && a[k] == val);
  loop assigns i, val;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] >= val))
      {
        val = a[i];
        /*@ assert val == a[i]; */
      }
      /*@ assert \forall integer j; 0 <= j <= i ==> a[j] <= val; */
      i = (i + 1);
    }
  /*@ assert i == a_len; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] <= val; */
  /*@ assert \exists integer j; 0 <= j < a_len && a[j] == val; */
  return val;
}