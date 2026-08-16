// Generated C + ACSL

/*@
    requires \valid_read(data + (0 .. max));
    requires 0 <= wr <= max;
    requires 0 <= rd <= max;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int Valid(int wr, int rd, int max, int *data, int data_length, int *Elements, int elements_count)
{
  int this_in_Repr = 1;
  int data_in_Repr = 1;

  if (!(this_in_Repr && data_in_Repr && (wr <= max) && (rd <= max) && (data_length == (max + 1))))
    return 0;

  if (rd <= wr) {
    return 1;
  } else {
    return 1;
  }
}