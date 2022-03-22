#include "stdafx.h"
#include "./SEncryption.h"
#include "MCrypt.h"
#include <Mmsystem.h>
#include <math.h>

#define DATA_INTERNATIONAL	 "7645878573421232"
#define DATA_LAUNCHDEV		 "5687686786453242"
#define DATA_TEST			 "2312312312354545"
#define DATA_DEVILGUNZ		 "1234812135324987"

// Test
DWORD Test( const char* szValue)
{
	int nCount = 0;
	DWORD dwValue = 0;

	while ( *(szValue + nCount) != 0)
	{
		dwValue *= 16;

		if ( ( *(szValue + nCount) >= '0') && ( *(szValue + nCount) <= '9'))
			dwValue += *(szValue + nCount) - '0';
		else
			dwValue += *(szValue + nCount) - 'A' + 10;

		nCount++;
	}

	return dwValue;
}


// GetEncription
int SEncryption::Decription( void)
{
	unsigned char szSerialKey[ MAX_BUF];
	memset( szSerialKey, 0, MAX_BUF);


	// Read from clipboard
	if ( ! ::OpenClipboard( NULL))
	{
		mlog( "ERROR : 1001\n");
		return false;
	}

	if ( !IsClipboardFormatAvailable( CF_GUNZLAUNCHER))
	{
		mlog( "ERROR : 1002\n");
		return false;
	}

	memcpy( szSerialKey, (unsigned char*)GetClipboardData( CF_GUNZLAUNCHER), MAX_BUF);

	::CloseClipboard();


	// Variables;
	char szTime[ 20];
	memset( szTime, 0, sizeof( szTime));

	char szDiskSerial[ 20];
	memset( szDiskSerial, 0, sizeof( szDiskSerial));

	char szData[ 20];
	memset( szData, 0, sizeof( szData));


	// Decrypt
	MSeed cSeed;
	unsigned char byKey[ SEED_USER_KEY_LEN];
	memset( byKey, 0, sizeof( byKey));
	unsigned char byIV[ SEED_BLOCK_LEN];
	memset( byIV, 0, sizeof( byIV));
	for ( int i = 0;  i < 20;  i++)
	{
		if ( i < SEED_USER_KEY_LEN)
			byKey[ i] = szSerialKey[ 200 + i];
		if ( i < SEED_BLOCK_LEN)
	        byIV[ i]  = szSerialKey[ 220 + i];
	}
	if ( !cSeed.InitKey( byKey, byIV))
	{
		mlog( "ERROR : 1003\n");
		return false;
	}

	DWORD dwLength;
	unsigned char szCryptSerialKey[ MAX_BUF];
	if ( !cSeed.Decrypt( szSerialKey, szSerialKey[ MAX_BUF - 3], szCryptSerialKey, &dwLength))
	{
		mlog( "ERROR : 1004\n");
		return false;
	}

	memcpy( szSerialKey, szCryptSerialKey, dwLength);



	// Check CRC
	unsigned char byCRC = 0;
	for ( int i = 0;  i < 60;  i++)
		byCRC += szSerialKey[ i];

	if ( byCRC != szSerialKey[ MAX_BUF - 2])
	{
		mlog( "ERROR : 1005\n");
		return false;
	}


	// Decoding
	int nPos = szSerialKey[ 60] % 10;
	for ( int i = 0;  i < 20;  i++)
	{
		int nAbsPos = (int)((i / 10) * 10) + nPos;

		szTime[ nAbsPos]        = (char)szSerialKey[      nAbsPos];
		szDiskSerial[ nAbsPos]  = (char)szSerialKey[ 20 + nAbsPos];
		szData[ nAbsPos]        = (char)szSerialKey[ 40 + nAbsPos];

		nPos = ( nPos + 3) % 10;
	}


	// Check time
	DWORD dwTime = Test( szTime);
	DWORD dwCurrTime = timeGetTime();
	if ( (DWORD)Test( szTime) < timeGetTime())
	{
		mlog( "ERROR : 1006\n");
		return false;
	}


	// Check serial number
	char szDiskLabel[ 128];
	char szFileSysName[ 128];
	DWORD dwDiskSerial;
	DWORD dwMaxNameLength = 0; 
	DWORD dwFileSystemFlags = 0;
	char szDirectory[ 256];
	GetCurrentDirectory( sizeof( szDirectory), szDirectory);
	szDirectory[ 3] = 0;
	GetVolumeInformation( szDirectory, szDiskLabel, sizeof(szDiskLabel)-1, &dwDiskSerial,
														&dwMaxNameLength,
														&dwFileSystemFlags,
														szFileSysName,
														sizeof( szFileSysName) - 1);

	if ( (DWORD)Test( szDiskSerial) != dwDiskSerial)
	{
		mlog( "ERROR : 1007\n");
		return false;
	}


	if ( strcmp( szData, DATA_INTERNATIONAL) == 0)
		return S_LAUNCH_INTERNATIONAL;
	else if ( strcmp( szData, DATA_LAUNCHDEV) == 0)
		return S_LAUNCH_DEVELOP;
	else if ( strcmp( szData, DATA_TEST) == 0)
		return S_LAUNCH_TEST;
	else if ( strcmp( szData, DATA_DEVILGUNZ) == 0)
		return S_LAUNCH_DEVILGUNZ;


	mlog( "ERROR : 1008\n");
	return false;
}
