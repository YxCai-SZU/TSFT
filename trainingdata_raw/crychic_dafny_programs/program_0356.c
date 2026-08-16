// Generated C + ACSL

/*@
    requires items != \null;
    requires items_len >= 0;
    requires \valid_read(items + (0 .. items_len-1));
    assigns \nothing;
    ensures \result < items_len;
    ensures \result >= 0 ==> items[\result] == item;
    ensures \result >= 0 ==>
        \forall integer x; \result < x < items_len ==> items[x] != item;
    ensures \result < 0 ==>
        \forall integer x; 0 <= x < items_len ==> items[x] != item;
*/
int lastIndexOf(int* items, int items_len, int item)
{
  int r = items_len;
  /*@ assert r >= 0 && r <= 2147483647; */
/*@
  loop invariant 0 <= r <= \at(r, LoopEntry);
  loop invariant \forall integer x; r <= x < \at(r, LoopEntry) ==> items[x] != item;
  loop assigns r;
  loop variant r;
*/
  while ((r > 0))
    {
      r = (r - 1);
      if ((items[r] == item))
      {
        return r;
      }
    }
  r = -1;
  return r;  // Dafny implicit return
}