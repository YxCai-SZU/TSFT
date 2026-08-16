// Generated C + ACSL

typedef struct {
    int x;
    int y;
} Score;

/*@
    requires s != \null;
    requires s_len == 3;
    requires \valid_read(s + (0 .. s_len-1));
    requires s[1] == ':';
    requires '0' <= s[0] <= '4';
    requires '0' <= s[2] <= '4';
    assigns \nothing;
    ensures 0 <= \result.x <= 4;
    ensures 0 <= \result.y <= 4;
*/
Score ParseScore(char* s, int s_len)
{
  int x = ((int)s[0] - (int)'0');
  int y = ((int)s[2] - (int)'0');
  Score score = {x, y};
  return score;
}

/*@
    requires scores != \null;
    requires scores_len == 10;
    requires \valid_read(scores + (0 .. scores_len-1));
    requires \forall integer i; 0 <= i < scores_len ==>
        scores[i] != \null &&
        \valid_read(scores[i] + (0 .. 2)) &&
        scores[i][1] == ':' &&
        '0' <= scores[i][0] <= '4' &&
        '0' <= scores[i][2] <= '4';
    assigns \nothing;
    ensures 0 <= \result <= 30;
*/
int TotalPoints(char** scores, int scores_len)
{
  int total = 0;
  /*@ assert total >= 0 && total <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= scores_len;
  loop invariant 0 <= total <= i * 3;
  loop invariant total <= \at(total, LoopEntry) + i * 3;
  loop assigns i, total;
  loop variant scores_len - i;
*/
  while ((i < scores_len))
    {
      Score score = ParseScore(scores[i], 3);
      if ((score.x > score.y))
      {
        total = (total + 3);
      }
      else
      if ((score.x == score.y))
      {
        total = (total + 1);
      }
      i = (i + 1);
    }
  return total;
}