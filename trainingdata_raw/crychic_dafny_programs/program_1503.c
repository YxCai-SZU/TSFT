// Generated C + ACSL

struct Card {
  char suit;
  int value;
};

/*@
  predicate validCard(struct Card c) =
    (c.suit == 'C' || c.suit == 'H' || c.suit == 'D' || c.suit == 'S') &&
    c.value >= 2 && c.value <= 14;
*/

/*@
  predicate Valid(integer numPlayers, int *players, integer players_len,
                  struct Card *currentDeck, integer currentDeck_len) =
    (numPlayers == 2 || numPlayers == 3 || numPlayers == 4) &&
    players_len == numPlayers &&
    currentDeck_len <= 52 &&
    \forall integer i; 0 <= i && i < currentDeck_len ==> validCard(currentDeck[i]);
*/

/*@
    assigns \nothing;
*/
void SetDeck(void)
{
  int suits = 0;
  int newDeck[52];
  int i = 0;
/*@
  loop invariant 0 <= i <= 4;
  loop invariant i * 13 <= 52;
  loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < 4;
  loop assigns i, newDeck[0 .. 51];
  loop variant 4 - i;
*/
  while ((i < 4))
    {
      int j = 2;
/*@
  loop invariant 2 <= j <= 15;
  loop invariant j - 2 <= 13;
  loop assigns j, newDeck[0 .. 51];
  loop variant 15 - j;
*/
      while ((j <= 14))
        {
          int idx = i * 13 + (j - 2);
          newDeck[idx] = 0;
          j = (j + 1);
        }
      i = (i + 1);
    }
  int n = 52;
  i = (n - 1);
/*@
  loop invariant -1 <= i < n;
  loop invariant n == \at(n, LoopEntry);
  loop invariant \at(n, LoopEntry) == 52;
  loop invariant \valid(newDeck + (0 .. n-1));
  loop assigns i, newDeck[0 .. n-1];
  loop variant i;
*/
  while ((i > 0))
    {
      int j = (i - 1);
      int temp = newDeck[i];
      newDeck[i] = newDeck[j];
      newDeck[j] = temp;
      i = (i - 1);
    }
  int* currentDeck = newDeck;
}