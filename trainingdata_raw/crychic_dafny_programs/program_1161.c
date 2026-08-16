// Generated C + ACSL

/*@
    requires args != \null;
    requires args_len >= 1;
    requires \valid(args + (0 .. args_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int Main(char** args, int args_len);

/*@
    requires args != \null;
    requires args_len >= 1;
    requires \valid_read(args + (0 .. args_len-1));
    assigns \nothing;
    ensures \result >= 0 || \result == -1;
*/
int ProcessRuntime(char** args, int args_len)
{
  int success = 1;
  int result;
  if (success)
  {
    result = 0;
    /*@ assert result >= 0 && result <= 2147483647; */
  }
  else
  {
    result = -1;
  }
  return result;  // Dafny implicit return
}

int Main(char** args, int args_len)
{
  int exitCode = 0;
  /*@ assert exitCode >= 0 && exitCode <= 2147483647; */
  if ((args_len < 1))
  {
    /* unsupported stmt: print "Error: Invalid arguments\n"; */
    exitCode = 1;
    return exitCode;
  }
  int result = ProcessRuntime(args, args_len);
  /* unsupported stmt: match result {
  case {:split 0} Some(code) =>
    exitCode := code;
  case {:split 0} None =>
    exitCode := 1;
} */
  if (result >= 0) {
    exitCode = result;
  } else {
    exitCode = 1;
  }
  return exitCode;  // Dafny implicit return
}