# 中文
# FreeRTOS的移植
本项目是使用keil5在STM32F103ZE上做相关的移植。因此需要打开本项目请使用最新的keil5打开。

keil5下载地址：http://www.keil.com/demo/eval/arm.htm

同时请下载相关的pack包：[Keil.STM32F1xx_DFP.2.1.0.pack]http://www.keil.com/dd2/pack/

## 下载固体库包
可以到openedv的网站进行下载[固体库v3.5.0](http://openedv.com/posts/list/6054.htm)

### 新建库函数项目
clearobj.bat将帮助你清空所有的东西。
注意填入：STM32F10X_HD,USE_STDPERIPH_DRIVER

##移植FreeRTOS
改错：
> ..\OBJ\FreeRTOS.axf: Error: L6218E: Undefined symbol vApplicationTickHook (referred from tasks.o).

在sys.c中加入函数

```
void vApplicationTickHook(void)
{
  
}
```

## 相关参考网站
http://www.openedv.com/thread-60571-1-1.html