// Generated C + ACSL

#include <string.h>
#include <stdlib.h>

/*@
    requires message != \null;
    requires message_len > 0;
    requires \valid_read(message + (0 .. message_len-1));
    requires args_len >= 0;
    requires args_len == 0 || (args != \null && \valid_read(args + (0 .. args_len-1)));
    requires \forall integer i; 0 <= i < args_len ==> (args[i] != \null);
    assigns \nothing;
*/
void log_message(char* message, int message_len, char** args, int args_len)
{
  char* result = "";
  int i = 0;
  int argIndex = 0;
/*@
  loop invariant 0 <= i <= message_len;
  loop invariant 0 <= argIndex <= args_len;
  loop invariant \at(argIndex, LoopEntry) <= argIndex;
  loop invariant i >= \at(i, LoopEntry);
  loop invariant argIndex - \at(argIndex, LoopEntry) <= (i - \at(i, LoopEntry) + 1) / 2;
  loop assigns i, argIndex, result;
  loop variant message_len - i;
*/
  while ((i < message_len))
    {
      if (((((i + 1) < message_len) && (message[i] == '{')) && (message[(i + 1)] == '}')))
      {
        if ((argIndex < args_len))
        {
          result = args[argIndex];
          argIndex = (argIndex + 1);
        }
        else
        {
          result = "{}";
        }
        i = (i + 2);
      }
      else
      {
        i = (i + 1);
      }
    }
  /* unsupported stmt: print result, "\n"; */
}