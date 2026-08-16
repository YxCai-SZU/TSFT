// Generated C + ACSL

#include <string.h>

#define StockNotFound(msg, len) (0)
#define DateNotInRange(msg, len) (-1)
#define HTMLElementNotFound(msg, len) (-2)
#define Success (1)

/*@
    requires message != \null;
    requires message_len >= 0;
    requires \valid_read(message + (0 .. message_len-1));
    assigns \nothing;
    ensures \result == 0;
*/
int CreateStockNotFoundError(char* message, int message_len)
{
  return StockNotFound(message, message_len);
}

/*@
    requires message != \null;
    requires message_len >= 0;
    requires \valid_read(message + (0 .. message_len-1));
    assigns \nothing;
    ensures \result == -1;
*/
int CreateDateNotInRangeError(char* message, int message_len)
{
  return DateNotInRange(message, message_len);
}

/*@
    requires message != \null;
    requires message_len >= 0;
    requires \valid_read(message + (0 .. message_len-1));
    assigns \nothing;
    ensures \result == -2;
*/
int CreateHTMLElementNotFoundError(char* message, int message_len)
{
  return HTMLElementNotFound(message, message_len);
}

/*@
    requires input != \null;
    requires input_len >= 0;
    requires \valid_read(input + (0 .. input_len-1));
    assigns \nothing;
    ensures (input_len == 0) ==> (\result == 0);
    ensures (input_len != 0) ==> (\result == 1);
*/
int ExampleUsage(char* input, int input_len)
{
  if (input_len == 0)
  {
    int error = CreateStockNotFoundError("Stock symbol cannot be empty", 29);
    return error;
  }
  return Success;
}