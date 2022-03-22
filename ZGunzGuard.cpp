include "stdafx.h"
#include "ZGunzGuard.h"
#include "ZGameguard.h"
#include "ZPost.h"
#include "CGLEncription.h"

#pragma comment( lib, "ws2_32.lib" )
#pragma comment( lib, "winmm.lib" )


ZGunzGuard& GetZGunzGuard()
{
	return ZGunzGuard::GetInstance();
}

ZGunzGuard::ZGunzGuard()
{
	m_bIsExitGame = false;
}

ZGunzGuard::~ZGunzGuard()
{
	Main();
}


bool ZGunzGuard::Main()
{	
		return true;
}

bool ZGunzGuard::LauncherSecurity()
{
return false;
}

