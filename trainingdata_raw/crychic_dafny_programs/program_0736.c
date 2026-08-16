// Generated C + ACSL

/*@
    requires main != \null;
    requires main_len > 0;
    requires \valid(main + (0 .. main_len-1));
    assigns \nothing;
*/
void PrintPairs(int* main, int main_len)
{
  int side = 0;
/*@
  loop invariant 0 <= side <= main_len;
  loop assigns side;
  loop variant main_len - side;
*/
  while ((side < main_len))
    {
      int x = 0;
/*@
  loop invariant 0 <= x <= main_len;
  loop invariant 0 <= side < main_len;
  loop invariant side == \at(side, LoopEntry);
  loop assigns x;
  loop variant main_len - x;
*/
      while ((x < main_len))
        {
          if ((main[side] != main[x]))
          {
            /* unsupported stmt: print main[side], ",", main[x], "\n"; */
          }
          x = (x + 1);
        }
      side = (side + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int arr[5]; /* unsupported init: Microsoft.Dafny.AllocateArray */
  /* unsupported stmt: arr[0], arr[1], arr[2], arr[3], arr[4] := 1, 2, 3, 4, 5; */
  PrintPairs(arr, 5);;
}