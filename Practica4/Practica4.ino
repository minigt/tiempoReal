#include <Arduino_FreeRTOS.h>

void TaskBlink1( void *pvParameters );
void TaskBlink2( void *pvParameters );
void TaskBlink3( void *pvParameters );

void setup() {

  xTaskCreate(
    TaskBlink1
    ,  (const portCHAR *)"Blink1"   
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskBlink2
    ,  (const portCHAR *)"Blink2"
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskBlink3
    ,  (const portCHAR *)"Blink3"
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

   Serial.begin(1152000);
}

void loop()
{
  
}

/*--------------------------------------------------*/
/*---------------------- Tareas ---------------------*/
/*--------------------------------------------------*/

void TaskBlink1(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;) // Loop infinito
  {
    Serial.println("Blink1");
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // espero 1 segundo
  }
}

void TaskBlink2(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;) // Loop infinito
  {
    Serial.println("Blink2");
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // espero 1 segundo
  }
}

void TaskBlink3(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;) // Loop infinito
  {
    Serial.println("Blink3");
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // espero 1 segundo
  }
}
