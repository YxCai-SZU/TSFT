// Generated C + ACSL

/*@
    requires a != \null;
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    requires \forall integer i; 0 <= i < a_len ==> a[i] <= 1000;
    assigns \nothing;
    ensures \forall integer k, j; 0 <= k < j < a_len ==> \result >= a[j] - a[k];
    ensures \result >= 0;
*/
int stock(int* a, int a_len)
{
  int max = 0;
  /*@ assert max >= 0 && max <= 2147483647; */
  if ((a_len < 2))
  {
    return max;
  }
  int lowPrice = a[0];
  int i = 0;
/*@
  loop invariant 0 <= i <= a_len;
  loop invariant max >= 0;
  loop invariant \forall integer j; 0 <= j < i ==> lowPrice <= a[j];
  loop invariant \forall integer k, j; 0 <= k < j < i ==> max >= a[j] - a[k];
  loop invariant \forall integer j; 0 <= j < i ==>
                   (\forall integer k; 0 <= k <= j ==> a[j] - a[k] <= max);
  loop invariant lowPrice == \at(lowPrice, LoopEntry) ||
                   (\exists integer j; 0 <= j < i && lowPrice == a[j]);
  loop invariant \forall integer j; 0 <= j < i ==>
                   a[j] == \at(a[j], LoopEntry);
  loop assigns i, lowPrice, max;
  loop variant a_len - i;
*/
  while ((i < a_len))
    {
      if ((a[i] < lowPrice))
      {
        lowPrice = a[i];
      }
      else
      if (((a[i] - lowPrice) > max))
      {
        max = (a[i] - lowPrice);
      }
      i = (i + 1);
    }
  return max;
}
