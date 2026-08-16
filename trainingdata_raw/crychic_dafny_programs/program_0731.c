// Generated C + ACSL

/*@
    requires \valid(matrix + (0 .. 11));
    assigns \nothing;
*/
void PrintMatrix(int *matrix)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= 3;
  loop assigns i;
  loop variant 3 - i;
*/
  while ((i < 3))
    {
      /* unsupported stmt: print "\n"; */
      int j = 0;
/*@
  loop invariant 0 <= j <= 4;
  loop invariant i == \at(i, LoopEntry);
  loop assigns j;
  loop variant 4 - j;
*/
      while ((j < 4))
        {
          /* unsupported stmt: print matrix[i * 4 + j]; */
          /* unsupported stmt: print "\t"; */
          j = (j + 1);
        }
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int matrix[12];
  matrix[0 * 4 + 0] = 1;
  matrix[0 * 4 + 1] = 2;
  matrix[0 * 4 + 2] = 3;
  matrix[0 * 4 + 3] = 4;
  matrix[1 * 4 + 0] = 5;
  matrix[1 * 4 + 1] = 6;
  matrix[1 * 4 + 2] = 7;
  matrix[1 * 4 + 3] = 8;
  matrix[2 * 4 + 0] = 9;
  matrix[2 * 4 + 1] = 10;
  matrix[2 * 4 + 2] = 11;
  matrix[2 * 4 + 3] = 12;
  PrintMatrix(matrix);;
}