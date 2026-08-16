// Generated C + ACSL

typedef struct {
    double toWin;
} Bet;

/*@
    requires bets != \null;
    requires bets_len >= 0;
    requires \valid(bets + (0 .. bets_len-1));
    assigns bets[0 .. bets_len-1];
*/
void AddToWinField(Bet* bets, int bets_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= bets_len;
  loop invariant \forall integer k; 0 <= k < i ==> bets[k].toWin == 0.0;
  loop invariant \forall integer k; 0 <= k < bets_len ==> \valid(&bets[k]);
  loop assigns i, bets[0..bets_len-1].toWin;
  loop variant bets_len - i;
*/
  while ((i < bets_len))
    {
      bets[i].toWin = 0.0;
      i = (i + 1);
    }
}