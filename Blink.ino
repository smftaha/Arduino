/*
  Blink
  This example code is in the public domain.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#define   IO_PIN_LED  (2)
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(IO_PIN_LED, OUTPUT);
}

// the loop function runs over and over again forever
uint32_t  TickCnt;
void loop() {
  delay (1);
  TickCnt++;
  if (( TickCnt  &(64-1))  ==0)
    FT_LedRfr();
}

void	FT_LedRfr	(void)
{
	static	uint32_t	LLedId	=0x00010055;
	static	uint32_t	LIndx	=1;
	/////////////////
	LIndx<<=1;
	if ( LIndx  ==0)
		LIndx=1;
	/////////////////
	if	( LLedId	&LIndx)
		digitalWrite(IO_PIN_LED, LOW);
	else
		digitalWrite(IO_PIN_LED, HIGH);
}
