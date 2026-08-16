// Generated C + ACSL

/*@
    requires Array != \null;
    requires Array_len >= 0;
    requires \valid(Array + (0 .. Array_len-1));
    assigns Array[0 .. Array_len-1];
*/
void selectionSorted(int* Array, int Array_len)
{
  int idx = 0;
/*@
  loop invariant 0 <= idx <= Array_len;
  loop invariant \forall integer i, j; 0 <= i < idx && idx <= j < Array_len ==> Array[i] <= Array[j];
  loop invariant \forall integer i, j; 0 <= i < j && j < idx ==> Array[i] <= Array[j];
  loop invariant \valid(Array + (0..Array_len-1));
  loop assigns idx, Array[0..Array_len-1];
  loop variant Array_len - idx;
*/
  while ((idx < Array_len))
    {
      int minIndex = idx;
      int idx_prime = (idx + 1);
/*@
  loop invariant idx < idx_prime <= Array_len;
  loop invariant idx <= minIndex < idx_prime;
  loop invariant minIndex < Array_len;
  loop invariant \forall integer k; idx <= k < idx_prime ==> Array[minIndex] <= Array[k];
  loop invariant idx_prime >= idx + 1;
  loop invariant idx_prime == (idx + 1) + (idx_prime - \at(idx_prime, LoopEntry));
  loop assigns idx_prime, minIndex;
  loop variant Array_len - idx_prime;
*/
      while ((idx_prime < Array_len))
        {
          /*@ assert idx <= minIndex < idx_prime; */
          /*@ assert \forall integer k; idx <= k < idx_prime ==> Array[minIndex] <= Array[k]; */
          if ((Array[idx_prime] < Array[minIndex]))
          {
            minIndex = idx_prime;
          }
          /*@ assert idx <= minIndex <= idx_prime; */
          /*@ assert \forall integer k; idx <= k <= idx_prime ==> Array[minIndex] <= Array[k]; */
          idx_prime = (idx_prime + 1);
        }
      /*@ assert idx <= minIndex < Array_len; */
      /*@ assert \forall integer k; idx <= k < Array_len ==> Array[minIndex] <= Array[k]; */
      int temp = Array[idx];
      Array[idx] = Array[minIndex];
      Array[minIndex] = temp;
      /*@ assert \forall integer k; idx < k < Array_len ==> Array[idx] <= Array[k]; */
      idx = (idx + 1);
    }
}