// Generated C + ACSL

#include <stddef.h>

int *cells;
size_t cells_length;
int write_position;
int read_position;
int isFlipped;
int isSuccess;
int content;

/*@
  predicate Valid(int *cells, integer cells_len, integer write_position, integer read_position) =
    0 <= write_position && write_position < cells_len &&
    0 <= read_position && read_position < cells_len;
*/

/*@
  predicate isEmpty(integer write_position, integer read_position) =
    write_position == read_position;
*/

/*@
  predicate isFull(integer write_position, integer read_position) =
    write_position == read_position - 1;
*/

/*@
    requires \valid(cells + (0 .. cells_length-1));
    requires cells_length > 0;
    requires 0 <= write_position < cells_length;
    requires 0 <= read_position < cells_length;
    assigns read_position, isFlipped, isSuccess, content;
*/
void Read(void)
{
  if ((write_position == read_position))
  {
    isSuccess = 0;
    /*@ assert isSuccess >= 0 && isSuccess <= 2147483647; */
    content = 0;
    /*@ assert content >= 0 && content <= 2147483647; */
  }
  else
  {
    isSuccess = 1;
    content = cells[read_position];
    if (isFlipped)
    {
      if ((read_position == (cells_length - 1)))
      {
        read_position = 0;
        /*@ assert read_position >= 0 && read_position <= 2147483647; */
        isFlipped = 0;
        /*@ assert isFlipped >= 0 && isFlipped <= 2147483647; */
      }
      else
      {
        read_position = (read_position + 1);
      }
    }
    else
    {
      if ((read_position < (cells_length - 1)))
      {
        read_position = (read_position + 1);
      }
    }
  }
}

/*@
    requires \valid(cells + (0 .. cells_length-1));
    requires cells_length > 0;
    requires 0 <= write_position < cells_length;
    requires 0 <= read_position < cells_length;
    assigns cells[0 .. cells_length-1];
    assigns write_position;
    assigns isFlipped;
    assigns isSuccess;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> cells[\old(write_position)] == input;
    ensures \result == 0 ==> write_position == \old(write_position);
*/
int Write(int input)
{
  if (((read_position - 1) == write_position))
  {
    isSuccess = 0;
    /*@ assert isSuccess >= 0 && isSuccess <= 2147483647; */
  }
  else
  {
    if (isFlipped)
    {
      if ((write_position >= read_position))
      {
        isSuccess = 0;
      }
      else
      {
        cells[write_position] = input;
        write_position = (write_position + 1);
        /*@ assert write_position >= 0 && write_position <= 2147483647; */
        isSuccess = 1;
      }
    }
    else
    {
      if ((write_position < read_position))
      {
        isSuccess = 0;
      }
      else
      {
        isSuccess = 1;
        cells[write_position] = input;
        if ((write_position == (cells_length - 1)))
        {
          write_position = 0;
          isFlipped = 1;
          /*@ assert isFlipped >= 0 && isFlipped <= 2147483647; */
        }
        else
        {
          write_position = (write_position + 1);
        }
      }
    }
  }
  return isSuccess;
}