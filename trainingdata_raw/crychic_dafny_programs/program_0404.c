// Generated C + ACSL

/*@
  predicate inDifference(integer original_count, integer curr_count, integer key) =
    original_count > curr_count;
*/

/*@
    requires bags != \null;
    requires bags_len >= 0;
    requires \valid_read(bags + (0 .. bags_len-1));
    requires start <= end;
    assigns \nothing;
*/
int* narrowDown(int* bags, int bags_len, int start, int end)
{
  int i = 0;
  int* selected = (int*)0;
  /*@ assert selected == (int*)0; */
/*@
  loop invariant 0 <= i <= bags_len;
  loop invariant selected == (int*)0;
  loop assigns i, selected;
  loop variant bags_len - i;
*/
  while ((i < bags_len))
    {
      if (start <= bags[i] && bags[i] <= end)
      {
        selected = (int*)((long)selected + 0);
      }
      i = (i + 1);
    }
  return selected;
}