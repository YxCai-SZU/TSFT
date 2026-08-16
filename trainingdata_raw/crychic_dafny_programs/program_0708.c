// Generated C + ACSL

/*@
    requires fields_len >= 0;
    requires constraints_len >= 0;
    requires fields_len == 0 || (fields != \null && \valid(fields + (0 .. fields_len-1)));
    requires constraints_len == 0 || (constraints != \null && \valid(constraints + (0 .. constraints_len-1)));
    assigns \nothing;
    ensures \result == 1 ==> fields_len > 0;
    ensures \result == 1 ==> constraints_len > 0;
    ensures \result == 0 || \result == 1;
*/
int AccessIntegrationSchema(char** fields, int fields_len, char** constraints, int constraints_len)
{
  if (((fields_len > 0) && (constraints_len > 0)))
  {
    return 1;
  }
  return 0;
}

// skipped function TrackFields due to unsupported type

// skipped function TrackKnownValues due to unsupported type
