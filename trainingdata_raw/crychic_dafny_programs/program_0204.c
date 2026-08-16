// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len > 1;
    requires \valid_read(a + (0 .. a_len-1));
    assigns \nothing;
    ensures \forall integer i, j;
        0 <= i < a_len && 0 <= j < a_len ==>
        a[i] - a[j] <= \result;
*/
int MaxDifference(int* a, int a_len)
{
  int minVal = a[0];
  int maxVal = a[0];
  /*@ assert minVal == a[0]; */
  /*@ assert maxVal == a[0]; */
  /*@ assert minVal <= maxVal; */
  {
    int i = 1;
/*@
  loop invariant 1 <= i <= a_len;
  loop invariant minVal <= maxVal;
  loop invariant \exists integer k; 0 <= k < i && a[k] == minVal;
  loop invariant \exists integer k; 0 <= k < i && a[k] == maxVal;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] >= minVal;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= maxVal;
  loop assigns i, minVal, maxVal;
  loop variant a_len - i;
*/
    while ((i < a_len))
      {
        /*@ assert 0 <= i < a_len; */
        /*@ assert \valid_read(&a[i]); */
        if ((a[i] < minVal))
        {
          minVal = a[i];
          /*@ assert minVal == a[i]; */
          /*@ assert \exists integer k; 0 <= k < i+1 && a[k] == minVal; */
        }
        else
        if ((a[i] > maxVal))
        {
          maxVal = a[i];
          /*@ assert maxVal == a[i]; */
          /*@ assert \exists integer k; 0 <= k < i+1 && a[k] == maxVal; */
        }
        /*@ assert a[i] >= minVal; */
        /*@ assert a[i] <= maxVal; */
        i = (i + 1);
      }
  /*@ assert i == a_len; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] >= minVal; */
  /*@ assert \forall integer k; 0 <= k < a_len ==> a[k] <= maxVal; */
  }
  int diff = (maxVal - minVal);
  /*@ assert diff >= 0 && diff <= 2147483647; */
  /*@ assert \forall integer i, j; 0 <= i < a_len && 0 <= j < a_len ==> a[i] - a[j] <= diff; */
  return diff;  // Dafny implicit return
}