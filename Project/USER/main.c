
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "misc.h"

#include "led.h"


void LED0_Task(void * pvParameters);
void LED1_Task(void * pvParameters);

int main(void)
{
	LED_Init();
	
	xTaskCreate(LED0_Task, (const char *)"LED0", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, NULL);
	xTaskCreate(LED1_Task, (const char *)"LED1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);
	
	vTaskStartScheduler();
}

void LED0_Task(void * pvParameters)
{
	while (1)
	{
		LED0 = !LED0;
		vTaskDelay(800 / portTICK_RATE_MS);
	}
}

void LED1_Task(void * pvParameters)
{
	while (1)
	{
		LED1 = !LED1;
		vTaskDelay(500 / portTICK_RATE_MS);
	}
}
