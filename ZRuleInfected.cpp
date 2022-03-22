#include "stdafx.h"
#include "ZRuleInfected.h"
#include "ZPost.h"

// Infected
ZRuleInfected::ZRuleInfected(ZMatch* pMatch) : ZRule(pMatch)
{

}
ZRuleInfected::~ZRuleInfected()
{


}
// PRIVATED
void ZRuleInfected::AssignZombieKing(MUID& uidZombieKing)
{
	if (!ZGetGame()) return;

	for (ZCharacterManager::iterator itor = ZGetGame()->m_CharacterManager.begin();
		itor != ZGetGame()->m_CharacterManager.end(); ++itor)
	{
		ZCharacter* pCharacter = (ZCharacter*)(*itor).second;
		pCharacter->SetTagger(false);
	}

	ZCharacter* pZombieKing = (ZCharacter*)ZGetGame()->m_CharacterManager.Find(uidZombieKing);
	if (pZombieKing)
	{
		pZombieKing->SetTagger(true);
		if (!pZombieKing->IsDie())
		{
			float fMaxHP = 500.0f;
			float fMaxAP = 500.0f;

			pZombieKing->SetHP(fMaxHP);
			pZombieKing->SetAP(fMaxAP);

			char Chat[256];

			if ( uidZombieKing == ZGetMyUID())
				sprintf(Chat, "You Are The ZOMBIE KING");
			else
				sprintf(Chat, "RUN!!!");
			ZChatOutput(MCOLOR(255, 100, 100), Chat);
		}
	}
	m_uidZombieKing = uidZombieKing;

	// SET TEAM 
	SetTeamClassify(uidZombieKing);
}
void ZRuleInfected::SetTeamClassify(MUID& uidZombieKing)
{
	ZCharacter* pZombieKing = (ZCharacter*)ZGetGame()->m_CharacterManager.Find(uidZombieKing);
	if(pZombieKing)
		ZPostStageTeam(uidZombieKing, ZGetGameClient()->GetStageUID(), MMT_RED);
	else
		ZPostStageTeam(ZGetGameClient()->GetPlayerUID(), ZGetGameClient()->GetStageUID(), MMT_BLUE);
}

// PUBLIC
void ZRuleInfected::OnDrawZombieKing(MDrawContext* pDC) 
{
	//ENCODE_START
	ZRuleInfected* pRule = (ZRuleInfected*)ZGetGame()->GetMatch()->GetRule();
	if(pRule) {
		for(ZCharacterManager::iterator itor = ZGetGame()->m_CharacterManager.begin(); itor != ZGetGame()->m_CharacterManager.end(); ++itor)
		{
			rvector pos, screen_pos;
			ZCharacter* pCharacter = (ZCharacter*)(*itor).second;
			if (!pCharacter->IsVisible()) continue;
			if (pCharacter->IsDie()) continue;
			if (pCharacter->GetUID() != pRule->GetZombieKingUID()) continue;
			pos = pCharacter->GetPosition();
			ZObjectVMesh* pVMesh = pCharacter->m_pVMesh;
			RealSpace2::rboundingbox box;

			if (pVMesh == NULL) continue;
		
			box.vmax = pos + rvector(50.f, 50.f, 190.f);
			box.vmin = pos + rvector(-50.f, -50.f, 0.f);

			if (isInViewFrustum(&box, RGetViewFrustum()))
			{
				// 미니맵이면 z 값을 0에 맞춘다
				if(ZGetCamera()->GetLookMode()==ZCAMERA_MINIMAP) {
					rvector pos = pCharacter->GetPosition();	//mmemory proxy
					pos.z=0;
					screen_pos = RGetTransformCoord(pos);
				}else
					screen_pos = RGetTransformCoord(pCharacter->GetVisualMesh()->GetHeadPosition()+rvector(0,0,30.f));

				MFont *pFont=NULL;
				MCOLOR CharNameColor;
				ZGetGame()->GetUserGradeIDColor(pCharacter->GetUserGrade(), CharNameColor, "");
				pFont = MFontManager::Get("FONTa12_O1Blr");
				pDC->SetColor(CharNameColor);
				pDC->SetBitmap(NULL);
				if (pFont == NULL) _ASSERT(0);
				pDC->SetFont(pFont);
				int x = screen_pos.x - pDC->GetFont()->GetWidth(pCharacter->GetUserName()) / 2;
				char Buffer[60];
				sprintf(Buffer, "[King] %s", pCharacter->GetUserName());
				pDC->Text(x, screen_pos.y - 12, Buffer);
			}
		}
	}
	//ENCODE_END
}