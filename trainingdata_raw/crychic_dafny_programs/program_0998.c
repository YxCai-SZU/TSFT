// Generated C + ACSL

/*@
    requires friends != \null;
    requires friends_len > 0;
    requires \valid(friends + (0 .. friends_len-1));
    requires \valid_read(friends[0 .. friends_len-1]);
    requires best_friend != \null;
    requires best_friend_len > 0;
    requires \valid_read(best_friend + (0 .. best_friend_len-1));
    assigns \nothing;
    ensures \result == 1 <==>
        (\exists integer i; 0 <= i < friends_len && friends[i] == best_friend);
    ensures \result == 0 <==>
        (\forall integer i; 0 <= i < friends_len ==> friends[i] != best_friend);
*/
int FindBestFriend(char** friends, int friends_len, char* best_friend, int best_friend_len)
{
  int i = 0;
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
/*@
  loop invariant 0 <= i <= friends_len;
  loop invariant found == 0 || found == 1;
  loop invariant found == 1 ==> \exists integer k; 0 <= k < i && friends[k] == best_friend;
  loop invariant found == 0 ==> \forall integer k; 0 <= k < i ==> friends[k] != best_friend;
  loop invariant \at(found, LoopEntry) == 1 ==> found == 1;
  loop assigns i, found;
  loop variant friends_len - i;
*/
  while ((i < friends_len))
    {
      if (friends[i] == best_friend)
      {
        found = 1;
        return found;
      }
      i = (i + 1);
    }
  return found;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  char* friends_array[] = {"Bob", "Charlie", "Allen"};
  char* best_friend = "Allen";
  int found = FindBestFriend(friends_array, 3, best_friend, 6);
  if (found)
  {
    /* unsupported stmt: print best_friend + " is inside the list!\n"; */
  }
  else
  {
    /* unsupported stmt: print best_friend + " is not in the list.\n"; */
  }
  /* unsupported stmt: print "I am just a random line after the search\n"; */
}