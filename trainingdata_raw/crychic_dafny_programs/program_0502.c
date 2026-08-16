// Generated C + ACSL

/*@
    requires items != \null;
    requires items_len >= 0;
    requires \valid(items + (0 .. items_len-1));
    assigns \nothing;
    ensures \result < items_len;
    ensures \result >= 0 ==> items[\result] == item;
    ensures \result >= 0 ==> \forall integer k; 0 <= k < \result ==> items[k] != item;
    ensures \result < 0 ==> \forall integer k; 0 <= k < items_len ==> items[k] != item;
*/
int firstIndexOf(int* items, int items_len, int item)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= items_len;
  loop invariant \forall integer k; 0 <= k < i ==> items[k] != item;
  loop assigns i;
  loop variant items_len - i;
*/
  while ((i < items_len))
    {
      if ((items[i] == item))
      {
        return i;
      }
      i = (i + 1);
    }
  return -1;
}
