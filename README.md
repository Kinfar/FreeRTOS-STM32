# ����
# FreeRTOS����ֲ
����Ŀ��ʹ��keil5��STM32F103ZE������ص���ֲ�������Ҫ�򿪱���Ŀ��ʹ�����µ�keil5�򿪡�

keil5���ص�ַ��http://www.keil.com/demo/eval/arm.htm

ͬʱ��������ص�pack����[Keil.STM32F1xx_DFP.2.1.0.pack]http://www.keil.com/dd2/pack/

## ���ع�����
���Ե�openedv����վ��������[�����v3.5.0](http://openedv.com/posts/list/6054.htm)

### �½��⺯����Ŀ
clearobj.bat��������������еĶ�����
ע�����룺STM32F10X_HD,USE_STDPERIPH_DRIVER

##��ֲFreeRTOS
�Ĵ�
> ..\OBJ\FreeRTOS.axf: Error: L6218E: Undefined symbol vApplicationTickHook (referred from tasks.o).

��sys.c�м��뺯��

```
void vApplicationTickHook(void)
{
  
}
```

## ��زο���վ
http://www.openedv.com/thread-60571-1-1.html