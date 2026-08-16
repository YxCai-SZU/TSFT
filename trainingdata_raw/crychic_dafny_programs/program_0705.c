// Generated C + ACSL

/*@
    requires cards != \null;
    requires cards_len >= 0;
    requires \valid_read(cards + (0 .. cards_len-1));
    requires searchName != \null;
    requires searchName_len >= 0;
    requires \valid_read(searchName + (0 .. searchName_len-1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==>
        (\exists integer i; 0 <= i < cards_len && cards[i] == searchName[0]);
    ensures \result == 0 ==>
        (\forall integer i; 0 <= i < cards_len ==> cards[i] != searchName[0]);
*/
int FindCardByName(int* cards, int cards_len, char* searchName, int searchName_len)
{
  int found = 0;
  /*@ assert found >= 0 && found <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= cards_len;
  loop invariant found == 0 || found == 1;
  loop invariant found == 0 ==>
    \forall integer k; 0 <= k < i ==> cards[k] != searchName[0];
  loop invariant found == 1 ==>
    \exists integer k; 0 <= k < i && cards[k] == searchName[0];
  loop assigns i, found;
  loop variant cards_len - i;
*/
  while ((i < cards_len))
    {
      if ((cards[i] == searchName[0]))
      {
        found = 1;
        break;;
      }
      i = (i + 1);
    }
  return found;  // Dafny implicit return
}