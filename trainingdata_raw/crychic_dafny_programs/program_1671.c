// Generated C + ACSL

/*@
    requires rows > 0;
    requires cols > 0;
    requires matrix != \null;
    requires \valid(matrix + (0 .. rows * cols - 1));
    requires \forall integer i, j, k;
        0 <= i < rows && 0 <= j < k < cols ==>
        matrix[i * cols + j] <= matrix[i * cols + k];
    requires \forall integer i, j, k;
        0 <= i < k < rows && 0 <= j < cols ==>
        matrix[i * cols + j] <= matrix[k * cols + j];
    assigns \nothing;
    ensures \result == 1 <==>
        (\exists integer i, j;
            0 <= i < rows && 0 <= j < cols &&
            matrix[i * cols + j] == target);
    ensures \result == 0 <==>
        (\forall integer i, j;
            0 <= i < rows && 0 <= j < cols ==>
            matrix[i * cols + j] != target);
*/
int SearchMatrix(int *matrix, int rows, int cols, int target)
{
  int row = 0;
  int col = (cols - 1);
/*@
  loop invariant 0 <= row <= rows;
  loop invariant -1 <= col < cols;
  loop invariant \forall integer i, j;
    0 <= i < row && 0 <= j <= col ==> matrix[i * cols + j] < target;
  loop invariant \forall integer i, j;
    row <= i < rows && col < j < cols ==> matrix[i * cols + j] > target;
  loop invariant \forall integer i, j;
    0 <= i < row && 0 <= j < cols ==> matrix[i * cols + j] != target;
  loop invariant \forall integer i, j;
    0 <= i < rows && col < j < cols ==> matrix[i * cols + j] != target;
  loop assigns row, col;
  loop variant (rows - row) + (col + 1);
*/
  while (((row < rows) && (col >= 0)))
    {
      if ((matrix[row * cols + col] == target))
      {
        return 1;
      }
      else
      if ((matrix[row * cols + col] < target))
      {
        row = (row + 1);
      }
      else
      {
        col = (col - 1);
      }
    }
  return 0;
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int matrix[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  int result = SearchMatrix(matrix, 3, 3, 5);
}