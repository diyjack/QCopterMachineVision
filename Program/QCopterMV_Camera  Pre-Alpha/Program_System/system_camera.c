/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f4_system.h"
#include "system_camera.h"
#include "ff.h"
#include "diskio.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**��� : Camera_Enable
**�\�� : �}�l�ഫ�Ϥ�
**��J : None
**��X : None
**�ϥ� : Camera_Enable();
**=====================================================================================================*/
/*=====================================================================================================*/
void Camera_Enable( void )
{
  DMA_Cmd(DMA2_Stream1, ENABLE);
  DCMI_Cmd(ENABLE);
  DCMI_CaptureCmd(ENABLE);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**��� : Camera_Photograph
**�\�� : Take a picture
**��J : None
**��X : None
**�ϥ� : Camera_Photograph();
**=====================================================================================================*/
/*=====================================================================================================*/
u8 Camera_Photograph( const char* Path, const void* ImageBuf, uc32 ImageSize )
{
  FIL file;
  FRESULT res;
  u32 i = 0;

  DCMI_CaptureCmd(ENABLE);

  res = f_open(&file, Path, FA_CREATE_NEW | FA_WRITE);
  if(res != FR_OK)
    return ERROR;
  f_lseek(&file, 0);
  f_write(&file, ImageBuf, ImageSize, &i);
  f_close(&file);

  return SUCCESS;
}
/*=====================================================================================================*/
/*=====================================================================================================*/