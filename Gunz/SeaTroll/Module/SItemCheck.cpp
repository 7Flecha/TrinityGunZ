// ****************************************************************************
//  SItemCheck	Check hack by item
//  ---------------------------------------------------------------------------
//  Copyright (C)SeaTroll 2012 - All Rights Reserved
// ****************************************************************************
#include "stdafx.h"
#include "../../ZGameInterface.h"
#include "../../ZConfiguration.h"
#include "../../ZWorldItem.h"
#include "../../ZPost.h"
#include "./SItemCheck.h"

// ****************************************************************************
//								   SeaTroll Game Bools
// ****************************************************************************


// ****************************************************************************
//								   SeaTroll Item List
// ****************************************************************************
// Katana
// 1100	-	Training Sword
// 1101	-	Fuuna Shuriken
// 1102	-	Military Sword
// 1103	-	Light Weight Sword


// ****************************************************************************
//								   SeaTroll KillGunz
// ****************************************************************************
void SItemCheck::KillGunz(int nKillID)
{
	switch (nKillID)
	{
		case 1: SGame::SLog("ERROR: Melee Hacking.\n"); break;
		case 2:	SGame::SLog("ERROR: Flip Hacking.\n");	break;
		case 3:	SGame::SLog("ERROR: Massive Hacking.\n"); break;
	}
	ExitProcess(0);
}

// ****************************************************************************
//								   SeaTroll Item Check
// ****************************************************************************
void SItemCheck::MeleeItem(int ItemID, unsigned long int Time, int IsFirstMelee)
{
	char temp[256];
	static unsigned long int LastMeleeTime = 0;
	int Delay = 0;
	MMatchItemDesc* pItem = MGetMatchItemDescMgr()->GetItemDesc(ItemID);

	sprintf(temp, "[SANITHACK] - Melee, Item ID: %i, Item Delay: %i", ItemID, pItem->m_nDelay.Ref());
	SGame::SLog(temp);

	//mlog("ItemID: %i.\n", ItemID);
	//mlog("Item Delay: %i.\n", pItem->m_nDelay.Ref());
	//mlog("LastMeleeTime %i.\n", LastMeleeTime);
	//mlog("LastTime - NewTime %i.\n", Time-LastMeleeTime);

		 if(ItemID == 1001)		int Delay = pItem->m_nDelay.Ref();
	else if(ItemID == 1200)		int Delay = 100;
	else						int Delay = pItem->m_nDelay.Ref()-70;

	if(pItem && (Time - LastMeleeTime) <= (Delay))
	{	
		if(IsFirstMelee != 1) 
			SAntiHack::IsFirstMelee = 1;
		else
			SItemCheck::KillGunz(1);
	}
	LastMeleeTime = Time;
}

void SItemCheck::FlipCheck(unsigned long int Time, int IsFirstFlip)
{
	char temp[256];
	static unsigned long int LastFlipTime = 0;

	sprintf(temp, "[SANITHACK] - Flip, Time: %i, Last Time %i", Time, LastFlipTime);
	SGame::SLog(temp);

	if((Time - LastFlipTime) <= 350)
	{	
		if(IsFirstFlip != 1) 
			SAntiHack::IsFirstFlip = 1;
		else
			SItemCheck::KillGunz(2);
	}
	LastFlipTime = Time;
}

void SItemCheck::MassiveCheck(unsigned long int Time, int IsFirstMassive)
{
	char temp[256];
	static unsigned long int LastMassiveTime = 0;

	sprintf(temp, "[SANITHACK] - Massive, Time: %i, Last Time %i", Time, LastMassiveTime);
	SGame::SLog(temp);

	if((Time - LastMassiveTime) <= 600)
	{	
		if(IsFirstMassive != 1) 
			SAntiHack::IsFirstMassive = 1;
		else
			SItemCheck::KillGunz(3);
	}
	LastMassiveTime = Time;
}
