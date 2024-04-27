#include "freertos/task.h"
#include "freertos/FreeRTOS.h"

//this is to test side branch

// Task to be created.

// this is to test git diff *****

void vTaskCode( void * pvParameters )
{
 for( ;; )
 {
     // Task code goes here.
 }
}

// Function that creates a task.
void vOtherFunction( void )
{
static uint8_t ucParameterToPass;
TaskHandle_t xHandle = NULL;

 // Create the task, storing the handle.  Note that the passed parameter ucParameterToPass
 // must exist for the lifetime of the task, so in this case is declared static.  If it was just an
 // an automatic stack variable it might no longer exist, or at least have been corrupted, by the time
 // the new task attempts to access it.
 xTaskCreatePinnedToCore( vTaskCode, "some descriptive NAME", configMINIMAL_STACK_SIZE * 4, &ucParameterToPass, tskIDLE_PRIORITY, &xHandle );
    configASSERT( xHandle );

 // Use the handle to delete the task.
    if( xHandle != NULL )
    {
     vTaskDelete( xHandle );
    }
}

void app_main() {}