/**********************************************************************
  GunZ Launcher Enctiption

   file : CGLEncription.h
   desc : ���� ���࿡ �ʿ��� �ø��� Ű�� ��ȣȭ �Ѵ�.
***********************************************************************/


#ifndef _GLENCRIPTION_
#define _GLENCRIPTION_


#define MAX_BUF						255
#define CF_GUNZLAUNCHER				0x0562

#define GLE_LAUNCH_INTERNATIONAL	0xFFFF
#define GLE_LAUNCH_DEVELOP			0xFFFE
#define GLE_LAUNCH_TEST				0xFFFD
#define GLE_LAUNCH_DEVILGUNZ		0xFFFC

class CGLEncription
{
public:
	bool CreateSerialKey( int nLaunchMode);

//	int Decription( void);
};
#endif