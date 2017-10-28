#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t primerSemaforo ;
SemaphoreHandle_t segundoSemaforo ;
SemaphoreHandle_t tercerSemaforo ;

void Tarea1( void *pvParameters );
void Tarea2( void *pvParameters );
void Tarea3( void *pvParameters );

void setup() {

  xTaskCreate(
    Tarea1
    ,  (const portCHAR *)"Tarea1"   
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    Tarea2
    ,  (const portCHAR *)"Tarea2"
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    Tarea3
    ,  (const portCHAR *)"Tarea3"
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  
  if ( primerSemaforo == NULL ){
    primerSemaforo = xSemaphoreCreateMutex();  
    if ( ( primerSemaforo ) != NULL )
      xSemaphoreGive( ( primerSemaforo ) );  
  }

  if ( segundoSemaforo == NULL ){
    segundoSemaforo = xSemaphoreCreateMutex(); 
  }

  if ( tercerSemaforo == NULL ){
    tercerSemaforo = xSemaphoreCreateMutex();  
  }

   Serial.begin(1152000);
}

void loop()
{
  
}

/*--------------------------------------------------*/
/*---------------------- Tareas ---------------------*/
/*--------------------------------------------------*/

void Tarea1(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;) // Loop infinito
  {
    if ( xSemaphoreTake( primerSemaforo, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println("Tarea1");
      xSemaphoreGive( ( segundoSemaforo ) );  
    }
  }
}

void Tarea2(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;) // Loop infinito
  {
    if ( xSemaphoreTake( tercerSemaforo, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println("Tarea2");
      xSemaphoreGive( ( primerSemaforo ) );  
    }
  }
}

void Tarea3(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;) // Loop infinito
  {
    if ( xSemaphoreTake( segundoSemaforo, ( TickType_t ) 5 ) == pdTRUE ){
      Serial.println("Tarea3");
      xSemaphoreGive( ( tercerSemaforo ) );  
    }
  }
}
