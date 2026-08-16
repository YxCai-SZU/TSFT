// Generated C + ACSL

/*@
    requires errorCode == 0 || errorCode == 1 || errorCode == 2;
    assigns \nothing;
    ensures \result == 400 || \result == 1001 || \result == 1002 || \result == 1003;
    ensures (errorCode == 0) ==> (\result == 400 || \result == 1001);
    ensures (errorCode == 1) ==> (\result == 400 || \result == 1002);
    ensures (errorCode == 2) ==> (\result == 400 || \result == 1003);
*/
int GetErrorInfo(int errorCode)
{
  int info;
  switch(errorCode) {
    case 0:
      info = 1001;
      break;
    case 1:
      info = 1002;
      break;
    case 2:
      info = 1003;
      break;
    default:
      info = 400;
      break;
  }
  return info;
}

/*@
  predicate IsValidErrorCode(integer code) =
    1001 <= code && code <= 1003;
*/