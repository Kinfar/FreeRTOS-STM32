# ���İ�

## STM32����ⴴ��demo

#### ��������ļ�

keil5���ص�ַ��[keil5](http://www.keil.com/demo/eval/arm.htm)

������ص�pack����[Keil.STM32F1xx_DFP.2.1.0.pack](http://www.keil.com/dd2/pack/)

��ֲ�����freertosԴ�룺[FreeRTOSv9.0.0.exe](https://pan.baidu.com/s/1mi4Pk3A)

��ֲ�����STM32�̼��⣺[STM32F10x_StdPeriph_Lib_V3.5.0.rar](https://pan.baidu.com/s/1mh5UOD6)

####  �����������Ŀ

��������ͼ��ʾ����Ŀ�飺

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo1.PNG)

> BSPĿ¼����ص�driver.

>FreeRTOSĿ¼����������������ֲ�Ķ���

>LibrariesĿ¼����ֹ���ǹ��������Ĵ������£�

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo2.PNG)

>USER����main������������һЩ�û��Լ����Ƶ�һЩ�ļ�

�����Ľ�����صĲ������Բο�[STM32F1����ָ��-�⺯���汾_V3.1 .pdf](https://pan.baidu.com/s/1jIlqzxs)�ĵ�����

���׼����������ˣ������ص���������ֲFreeRTOSv9.0.0

## ��ֲFreeRTOSv9.0.0��STM32F103��

#### 1.1�򿪽�ѹ���Դ��

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo3.PNG)

#### 1.2˫���򿪡�FreeRTOS���ļ��У����������ļ�

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo4.PNG)

ͼ��ȦȦ�ľ���Դ���ˣ������ļ��п������½����̵ġ�FreeRTOS���ļ�����

#### 1.3��Դ���ļ�����**\FreeRTOS\Demo\CORTEX_STM32F103_Keil**���·���£��ҵ��ļ�**FreeRTOSConfig.h**�������������ļ���FreeRTOS��

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo5.PNG)

#### 1.4��keil������ļ�

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo6.PNG)

����ļ���������ʾ
    
> ��port.c���ļ�·��..\FreeRTOS\Source\portable\RVDS\ARM_CM3
     
> ��heap_2.c���ļ�·��..\FreeRTOS\Source\portable\MemMang
      
>��list.c������queue.c������tasks.c���ļ�·��..\FreeRTOS\Source

#### 1.5���ͷ�ļ�

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo7.PNG)

ע�����룺STM32F10X_HD,USE_STDPERIPH_DRIVER

#### 1.6�޸�main����

```

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
```

#### 1.7�޸������ļ�

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo7.PNG)

## ��������

����ֲ�����������д�����Ҫ����ȥ���

#### ����һ ����

> ..\OBJ\FreeRTOS.axf: Error: L6218E: Undefined symbol vApplicationTickHook (referred from tasks.o).

����ѡ����BSPĿ¼�������صĳ�����롣

```
void vApplicationTickHook(void)
{
  
}
```
