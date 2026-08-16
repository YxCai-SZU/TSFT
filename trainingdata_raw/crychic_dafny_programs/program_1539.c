// Generated C + ACSL

/*@
    requires friends >= 1;
    assigns \nothing;
*/
void AddFriends(int friends)
{
  int R1 = 0;
  int R2 = 0;
  int i = 0;
  int identities = 0;
/*@
  loop invariant identities == i;
  loop invariant 0 <= i <= friends;
  loop invariant i <= friends;
  loop assigns identities, i;
  loop variant friends - i;
*/
  while ((i < friends))
    {
      identities = (identities + 1);
      i = (i + 1);
    }
  identities = (identities - 1);
  R1 = (R1 + identities);
  /*@ assert (R1 <= friends); */
  /*@ assert 0 <= identities <= friends; */
  identities = 0;
  identities = (identities + 1);
  i = 0;
/*@
  loop invariant 0 <= i <= friends;
  loop invariant R2 == \at(R2, LoopEntry) - (i * identities);
  loop invariant R2 <= 0;
  loop invariant identities == \at(identities, LoopEntry);
  loop assigns i, R2;
  loop variant friends - i;
*/
  while ((i < friends))
    {
      R2 = (R2 - identities);
      /*@ assert (R2 <= 0); */
      i = (i + 1);
    }
  /*@ assert (R2 <= 0); */
}
