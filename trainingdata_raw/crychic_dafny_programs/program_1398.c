// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void removeMemberFromAllDiscussions(int n)
{
  int R = 0;
  int i = 0;
/*@
  loop invariant \at(R, LoopEntry) <= i;
  loop invariant i <= n;
  loop invariant R == \at(R, LoopEntry) + (i - \at(i, LoopEntry));
  loop invariant R <= i;
  loop assigns i, R;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
      R = (R + 1);
      /*@ assert (R <= i); */
    }
  /*@ assert (i <= n); */
  /*@ assert (R <= n); */
}
