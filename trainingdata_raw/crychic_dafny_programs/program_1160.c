// Generated C + ACSL

typedef enum {
  READY = 0,
  PAUSED = 1,
  PLAYING = 2
} State;

typedef enum {
  ERROR = 0,
  EOS = 1,
  BUFFERING = 2,
  CLOCK_LOST = 3
} MessageType;

typedef struct {
  MessageType msgType;
  int bufferingPercent;
} Message;

typedef struct {
  int isLive;
} Pipeline;

int currentState = 0;
int running = 0;
Pipeline pipeline = {0};

/*@
    requires 0 <= newState <= 2;
    assigns currentState;
    ensures \result == 1;
    ensures currentState == newState;
*/
int setState(int newState)
{
  currentState = newState;
  /*@ assert currentState >= 0 && currentState <= 2147483647; */
  int success = 1;
  /*@ assert success >= 0 && success <= 2147483647; */
  return success;
}

/*@
    requires msg.msgType == BUFFERING;
    requires 0 <= msg.bufferingPercent <= 100;
    assigns \nothing;
    ensures (msg.bufferingPercent < 100 ==> \result == PAUSED) &&
            (msg.bufferingPercent == 100 ==> \result == PLAYING);
    ensures 0 <= \result <= 2;
*/
int handleBuffering(Message msg)
{
  int newState;
  if ((msg.bufferingPercent < 100))
  {
    newState = PAUSED;
    /*@ assert newState >= 0 && newState <= 2147483647; */
  }
  else
  {
    newState = PLAYING;
  }
  /*@ assert 0 <= newState <= 2; */
  return newState;
}

/*@
    requires msg.msgType == BUFFERING ==> 0 <= msg.bufferingPercent <= 100;
    assigns currentState, running;
    ensures \result == 0 || \result == 1;
*/
int handleMessage(Message msg)
{
  int oldRunning = running;
  running = 1;
  /*@ assert running >= 0 && running <= 2147483647; */

  int shouldContinue = 1;

  switch (msg.msgType) {
    case ERROR:
      setState(READY);
      shouldContinue = 0;
      break;
    case EOS:
      setState(READY);
      shouldContinue = 0;
      break;
    case BUFFERING:
      if (!pipeline.isLive) {
        int newState = handleBuffering(msg);
        /*@ assert 0 <= newState <= 2; */
        setState(newState);
      }
      shouldContinue = 1;
      break;
    case CLOCK_LOST:
      setState(PAUSED);
      setState(PLAYING);
      shouldContinue = 1;
      break;
  }

  running = oldRunning;
  if (!(running))
  {
    shouldContinue = 0;
    /*@ assert shouldContinue >= 0 && shouldContinue <= 2147483647; */
  }
  return shouldContinue;
}