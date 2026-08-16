// Generated C + ACSL

/*@
    requires items != \null;
    requires items_len >= 0;
    requires \valid_read(items + (0 .. items_len-1));
    assigns \nothing;
    ensures \result > 0 ==>
        (\exists integer k; 0 <= k < items_len && items[k] == item);
    ensures \result == 0 ==>
        (\forall integer k; 0 <= k < items_len ==> items[k] != item);
*/
int occurences(int* items, int items_len, int item)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int count = 0;
  /*@ assert count >= 0 && count <= 2147483647; */
  /*@
    loop invariant 0 <= i <= items_len;
    loop invariant count > 0 ==> (\exists integer k; 0 <= k < i && items[k] == item);
    loop invariant count == 0 ==> (\forall integer k; 0 <= k < i ==> items[k] != item);
    loop invariant count >= 0;
    loop assigns i, count;
    loop variant items_len - i;
  */
  while ((i < items_len))
    {
      if ((items[i] == item))
      {
        count = (count + 1);
      }
      i = (i + 1);
    }
  return count;
}