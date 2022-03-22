#include "stdafx.h"
#include "MMatchRuleBountyHunter.h"
#include "MMatchTransDataType.h"
#include "MBlobArray.h"
#include "MMatchServer.h"

//////////////////////////////////////////////////////////////////////////////////
// MMatchRuleBounty ///////////////////////////////////////////////////////////
MMatchRuleBounty::MMatchRuleBounty(MMatchStage* pStage) : MMatchRuleSoloDeath(pStage), m_uidBounty(0,0)
{

}

bool MMatchRuleBounty::OnCheckRoundFinish()
{
	return MMatchRuleSoloDeath::OnCheckRoundFinish();
}

void MMatchRuleBounty::OnRoundBegin()
{
	m_uidBounty = MUID(0, 0);
	m_uidBounty = RecommendBounty();
	RouteAssignBounty();
}

void* MMatchRuleBounty::CreateRuleInfoBlob()
{
	void* pRuleInfoArray = MMakeBlobArray(sizeof(MTD_RuleInfo_Bounty), 1);
	MTD_RuleInfo_Bounty* pRuleItem = (MTD_RuleInfo_Bounty*)MGetBlobArrayElement(pRuleInfoArray, 0);
	memset(pRuleItem, 0, sizeof(MTD_RuleInfo_Bounty));
	pRuleItem->nRuleType = MMATCH_GAMETYPE_BOUNTY;
	pRuleItem->uidBounty = m_uidBounty;
	return pRuleInfoArray;
}

void MMatchRuleBounty::RouteAssignBounty()
{	MCommand* pNew = MMatchServer::GetInstance()->CreateCommand(MC_MATCH_ASSIGN_BERSERKER, MUID(0, 0));
	pNew->AddParameter(new MCmdParamUID(m_uidBounty));
	MMatchServer::GetInstance()->RouteToBattle(m_pStage->GetUID(), pNew);
}


MUID MMatchRuleBounty::RecommendBounty()
{
	MMatchStage* pStage = GetStage();
	if (pStage == NULL) return MUID(0,0);
	int nCount = 0;
	for(MUIDRefCache::iterator itor=pStage->GetObjBegin(); itor!=pStage->GetObjEnd(); itor++) {
		MMatchObject* pObj = (MMatchObject*)(*itor).second;
		if (pObj->GetEnterBattle() == false) continue;
		if (pObj->CheckAlive())
		{
			return pObj->GetUID();
		}
	}
	return MUID(0,0);
}

void MMatchRuleBounty::OnEnterBattle(MUID& uidChar)
{
}

void MMatchRuleBounty::OnLeaveBattle(MUID& uidChar)
{
	if (uidChar == m_uidBounty)
	{
		m_uidBounty = RecommendBounty();
		RouteAssignBounty();
	}
}

void MMatchRuleBounty::OnGameKill(const MUID& uidAttacker, const MUID& uidVictim)
{
	if ((m_uidBounty == uidVictim) || (m_uidBounty == MUID(0,0)))
	{
		m_uidBounty = MUID(0, 0);
		bool bAttackerCanBeBounty = false;
		if (uidAttacker != uidVictim)
		{
			MMatchObject* pAttacker = MMatchServer::GetInstance()->GetObject(uidAttacker);
			if ((pAttacker) && (pAttacker->CheckAlive()))
			{
				bAttackerCanBeBounty = true;
			}
		}
		else if ((uidAttacker == MUID(0,0)) || (uidAttacker == uidVictim))
		{
			bAttackerCanBeBounty = false;
		}

		if (bAttackerCanBeBounty) {
			m_uidBounty = uidAttacker;
		}
		else  
		{
			m_uidBounty = RecommendBounty();
		}
		RouteAssignBounty();
	}
}

