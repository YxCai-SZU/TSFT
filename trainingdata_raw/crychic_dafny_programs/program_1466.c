// Generated C + ACSL

/*@
  predicate Sorted(int *a, integer len, integer low, integer high) =
    \forall integer j, k; low <= j && j < k && k < high ==> a[j] >= a[k];
*/

/*@
    requires bList != \null;
    requires bList_len > 1;
    requires \valid(bList + (0 .. bList_len-1));
    assigns bList[0 .. bList_len-1];
*/
void sortByScore(int* bList, int bList_len)
{
  int i = 1;
/*@
  loop invariant 1 <= i <= bList_len;
  loop invariant \forall integer x, y;
                   0 <= x < y < i ==> bList[x] >= bList[y];
  loop invariant \forall integer k; 0 <= k < bList_len ==>
                   (\exists integer m; 0 <= m < bList_len &&
                    bList[k] == \at(bList[m], Pre));
  loop assigns i, bList[0..bList_len-1];
  loop variant bList_len - i;
*/
  while ((i < bList_len))
    {
      int j = i;
/*@
  loop invariant 0 <= j <= i;
  loop invariant \forall integer x, y;
                   0 <= x < y <= i && y != j ==> bList[x] >= bList[y];
  loop invariant \forall integer k; 0 <= k < bList_len ==>
                   (\exists integer m; 0 <= m < bList_len &&
                    bList[k] == \at(bList[m], LoopEntry));
  loop assigns j, bList[0..i];
  loop variant j;
*/
      while (((j >= 1) && (bList[(j - 1)] < bList[j])))
        {
          int temp = bList[j];
          bList[j] = bList[j - 1];
          bList[j - 1] = temp;
          j = (j - 1);
        }
      i = (i + 1);
    }
}