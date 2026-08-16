// Generated C + ACSL

/*@
    requires gridXIndexes_len > 0;
    requires gridXIndexes != \null;
    requires \valid_read(gridXIndexes + (0 .. gridXIndexes_len-1));
    requires \forall integer i, j; 0 <= i < j < gridXIndexes_len ==> gridXIndexes[i] < gridXIndexes[j];
    assigns \nothing;
    ensures -1 <= \result < gridXIndexes_len;
    ensures \result == -1 ==> mouseX < gridXIndexes[0];
    ensures \result >= 0 ==> mouseX >= gridXIndexes[\result] && (\result + 1 < gridXIndexes_len ==> mouseX <= gridXIndexes[\result + 1]);
*/
int GetGridX(int mouseX, int* gridXIndexes, int gridXIndexes_len)
{
  if ((mouseX < gridXIndexes[0]))
  {
    return -1;
  }
  int column = 0;
  /*@ assert column >= 0 && column <= 2147483647; */
/*@
  loop invariant 0 <= column <= gridXIndexes_len;
  loop invariant \forall integer i; 0 <= i < column ==> mouseX > gridXIndexes[i];
  loop invariant column < gridXIndexes_len ==> mouseX >= gridXIndexes[column];
  loop assigns column;
  loop variant gridXIndexes_len - column;
*/
  while ((column < gridXIndexes_len))
    {
      if ((((column + 1) >= gridXIndexes_len) || (mouseX <= gridXIndexes[(column + 1)])))
      {
        return column;
      }
      column = (column + 1);
    }
  return (gridXIndexes_len - 1);
}

/*@
    requires sunScore >= 0;
    assigns \nothing;
    ensures 0 <= \result <= 6;
    ensures sunScore < 50 ==> \result == 0;
    ensures 50 <= sunScore < 100 ==> \result == 2;
    ensures 100 <= sunScore < 125 ==> \result == 3;
    ensures 125 <= sunScore < 200 ==> \result == 5;
    ensures sunScore >= 200 ==> \result == 6;
*/
int GetCardRange(int sunScore)
{
  if ((sunScore < 50))
  {
    return 0;
  }
  else
  if ((sunScore < 100))
  {
    return 2;
  }
  else
  if ((sunScore < 125))
  {
    return 3;
  }
  else
  if ((sunScore < 200))
  {
    return 5;
  }
  else
  {
    return 6;
  }
}