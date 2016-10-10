# 中文版

## STM32固体库创建demo

#### 下载相关文件

keil5下载地址：[keil5](http://www.keil.com/demo/eval/arm.htm)

下载相关的pack包：[Keil.STM32F1xx_DFP.2.1.0.pack](http://www.keil.com/dd2/pack/)

移植所需的freertos源码：[FreeRTOSv9.0.0.exe](https://pan.baidu.com/s/1mi4Pk3A)

移植所需的STM32固件库：[STM32F10x_StdPeriph_Lib_V3.5.0.rar](https://pan.baidu.com/s/1mh5UOD6)

####  建立固体库项目

建立如下图所示的项目组：

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo1.PNG)

> BSP目录放相关的driver.

>FreeRTOS目录将放置我们所需移植的东西

>Libraries目录将防止我们固体库所需的代码如下：

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo2.PNG)

>USER放置main函数，并放置一些用户自己定制的一些文件

如何真的进行相关的操作可以参考[STM32F1开发指南-库函数版本_V3.1 .pdf](https://pan.baidu.com/s/1jIlqzxs)的第三章

差不多准备工作完成了，下面重点就是如何移植FreeRTOSv9.0.0

## 移植FreeRTOSv9.0.0到STM32F103中

#### 1.1打开解压后点源码

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo3.PNG)

#### 1.2双击打开“FreeRTOS”文件夹，看到如下文件

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo4.PNG)

图中圈圈的就是源码了，整个文件夹拷贝到新建工程的“FreeRTOS”文件夹中

#### 1.3在源码文件夹中**\FreeRTOS\Demo\CORTEX_STM32F103_Keil**这个路径下，找到文件**FreeRTOSConfig.h**，拷贝到工程文件夹FreeRTOS中

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo5.PNG)

#### 1.4打开keil，添加文件

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo6.PNG)

添加文件如上如所示
    
> “port.c”文件路径..\FreeRTOS\Source\portable\RVDS\ARM_CM3
     
> “heap_2.c”文件路径..\FreeRTOS\Source\portable\MemMang
      
>“list.c”、“queue.c”、“tasks.c”文件路径..\FreeRTOS\Source

#### 1.5添加头文件

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo7.PNG)

注意填入：STM32F10X_HD,USE_STDPERIPH_DRIVER

#### 1.6修改main函数

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

#### 1.7修改启动文件

![](https://raw.githubusercontent.com/NingbinWang/NingbinWang.github.io/master/img/post/stm32/demo/demo7.PNG)

## 遇到问题

在移植过程中难免有错误。需要我们去解决

#### 问题一 编译

> ..\OBJ\FreeRTOS.axf: Error: L6218E: Undefined symbol vApplicationTickHook (referred from tasks.o).

可以选择在BSP目录下添加相关的程序代码。

```
void vApplicationTickHook(void)
{
  
}
```
