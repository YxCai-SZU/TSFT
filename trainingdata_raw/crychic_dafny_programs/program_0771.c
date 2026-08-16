// Generated C + ACSL

/*@
  predicate Valid(int *blocks, integer blocks_len, integer score) =
    blocks_len == 81 && score >= 0;
*/

/*@
    requires blocks != \null;
    requires blocks_len > 0;
    requires \valid(blocks + (0 .. blocks_len-1));
    requires 0 <= pos < blocks_len;
    assigns blocks[pos];
*/
void update(int *blocks, int blocks_len, int pos, int marker)
{
  blocks[pos] = marker;
}

/*@
    requires blocks != \null;
    requires blocks_len > 0;
    requires 0 <= pos < blocks_len;
    requires 0 <= pos1 < blocks_len;
    requires pos != pos1;
    requires \valid(blocks + (0 .. blocks_len-1));
    assigns blocks[pos], blocks[pos1];
*/
void update2(int *blocks, int blocks_len, int pos, int pos1, int marker, int marker1)
{
  blocks[pos] = marker;
  blocks[pos1] = marker1;
}

/*@
    requires \valid(score);
    requires *score >= 0;
    requires *score < 2147483647;
    assigns *score;
    ensures *score == \old(*score) + 1;
    ensures *score >= 1;
*/
void scoreup(int *score)
{
  *score = (*score + 1);
  /*@ assert *score >= 0 && *score <= 2147483647; */
}

/*@
    requires blocks != \null;
    requires \valid_read(blocks + (0 .. blocks_len-1));
    requires Valid(blocks, blocks_len, score);
    assigns \nothing;
*/
void gprint(int *blocks, int blocks_len, int score)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= 9;
  loop invariant Valid(blocks, blocks_len, score);
  loop assigns i;
  loop variant 9 - i;
*/
  while ((i < 9))
    {
      int j = 0;
/*@
  loop invariant 0 <= j <= 9;
  loop invariant i == \at(i, LoopEntry);
  loop invariant Valid(blocks, blocks_len, score);
  loop assigns j;
  loop variant 9 - j;
*/
      while ((j < 9))
        {
          /* unsupported stmt: print blocks[i * 9 + j], " "; */
          j = (j + 1);
        }
      /* unsupported stmt: print "\n"; */
      i = (i + 1);
    }
  /* unsupported stmt: print "Score: ", score, "\n"; */
}