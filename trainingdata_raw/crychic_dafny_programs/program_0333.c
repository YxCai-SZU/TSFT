// Generated C + ACSL

/*@
    requires items != \null;
    requires items_len > 0;
    requires \valid(items + (0 .. items_len-1));
    assigns \nothing;
    ensures \forall integer k; 0 <= k < items_len ==> \result >= items[k];
    ensures \exists integer k; 0 <= k < items_len && \result == items[k];
*/
int maxArray(int* items, int items_len)
{
  int i = 1;
  int r = items[0];
  
  /*@ assert r == items[0]; */
  /*@ assert \forall integer k; 0 <= k < 1 ==> r >= items[k]; */
  
/*@
  loop invariant 0 < i <= items_len;
  loop invariant \forall integer k; 0 <= k < i ==> r >= items[k];
  loop invariant \exists integer j; 0 <= j < i && r == items[j];
  loop assigns i, r;
  loop variant items_len - i;
*/
  while ((i < items_len))
    {
      /*@ assert 0 <= i < items_len; */
      if ((items[i] > r))
      {
        r = items[i];
        /*@ assert r == items[i]; */
        /*@ assert \forall integer k; 0 <= k < i ==> r >= items[k]; */
      }
      /*@ assert \forall integer k; 0 <= k <= i ==> r >= items[k]; */
      i = (i + 1);
    }
  /*@ assert i == items_len; */
  /*@ assert \forall integer k; 0 <= k < items_len ==> r >= items[k]; */
  /*@ assert \exists integer j; 0 <= j < items_len && r == items[j]; */
  return r;  // Dafny implicit return
}