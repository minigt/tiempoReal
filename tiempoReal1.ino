#include <Arduino_FreeRTOS.h>
#include <avr/sleep.h>  // include the Arduino (AVR) sleep functions.

uint32_t value;

// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskAnalogRead( void *pvParameters );

// set_sleep_mode() options available:
// SLEEP_MODE_IDLE
// SLEEP_MODE_ADC
// SLEEP_MODE_PWR_DOWN
// SLEEP_MODE_PWR_SAVE
// SLEEP_MODE_STANDBY
// SLEEP_MODE_EXT_STANDBY

// the setup function runs once when you press reset or power the board
void setup() {

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
   Serial.begin(1152000);
   
  pinMode(2,OUTPUT);
  value=HIGH;
}

void loop()
{
  set_sleep_mode( SLEEP_MODE_PWR_DOWN );
  portENTER_CRITICAL();

  sleep_enable();
 
  // Only if there is support to disable the brown-out detection.
  // If the brown-out is not set, it doesn't cost much to check.
  #if defined(BODS) && defined(BODSE)
    sleep_bod_disable();
  #endif
 
  portEXIT_CRITICAL();

  sleep_cpu(); // Good night.
 
  // Ugh. Yawn... I've been woken up. Better disable sleep mode.
  // Reset the sleep_mode() faster than sleep_disable();
  sleep_reset();
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  /*
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  
  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
  */

  for (;;) // A Task shall never return or exit.
  {
    //LED_ON
    
    //value=not value;
    digitalWrite(2,value);
    Serial.println("Led on");
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    //LED_OFF
    Serial.println("Led off");
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}
