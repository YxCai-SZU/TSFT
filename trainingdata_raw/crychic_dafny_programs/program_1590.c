// Generated C + ACSL

// skipped function InitMeasures due to unsupported type

/*@
    requires streamingData != \null;
    requires streamingData_len > 0;
    requires \valid_read(streamingData + (0 .. streamingData_len-1));
    assigns \nothing;
*/
void ProcessDistance(int* streamingData, int streamingData_len)
{
  int threshold = 0;
  int maxSpread = 0.0;
  /*@ assert maxSpread >= 0 && maxSpread <= 2147483647; */
  int anomaly = 0;
  /*@ assert anomaly >= 0 && anomaly <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= streamingData_len;
  loop invariant maxSpread >= 0.0;
  loop invariant anomaly == 0 || anomaly == 1;
  loop invariant \forall integer k; 0 <= k < i ==>
    (streamingData[k] > threshold ==> anomaly == 1);
  loop invariant \forall integer k; 0 <= k < i ==>
    maxSpread >= streamingData[k];
  loop invariant maxSpread >= \at(maxSpread, LoopEntry);
  loop invariant i > 0 ==> maxSpread >= streamingData[i-1];
  loop assigns i, anomaly, maxSpread;
  loop variant streamingData_len - i;
*/
  while ((i < streamingData_len))
    {
      int currentValue = streamingData[i];
      /*@ assert currentValue == streamingData[i]; */
      if ((currentValue > threshold))
      {
        anomaly = 1;
        maxSpread = ((currentValue > maxSpread)) ? (currentValue) : (maxSpread);
        /*@ assert maxSpread >= currentValue; */
        /*@ assert maxSpread >= \at(maxSpread, LoopCurrent); */
      }
      else
      {
        maxSpread = ((currentValue > maxSpread)) ? (currentValue) : (maxSpread);
        /*@ assert maxSpread >= currentValue; */
        /*@ assert maxSpread >= \at(maxSpread, LoopCurrent); */
      }
      /*@ assert maxSpread >= streamingData[i]; */
      /*@ assert \forall integer k; 0 <= k < i ==> maxSpread >= streamingData[k]; */
      i = (i + 1);
    }
}