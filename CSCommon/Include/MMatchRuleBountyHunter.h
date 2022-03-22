#ifndef _MMATCHRULE_BOUNTY_H
#define _MMATCHRULE_BOUNTY_H


#include "MMatchRule.h"
#include "MMatchRuleDeathMatch.h"


class MMatchRuleBounty : public MMatchRuleSoloDeath {
protected:
	MUID		m_uidBounty;
	bool CheckKillCount(MMatchObject* pOutObject);
	virtual void OnRoundBegin();
	virtual bool OnCheckRoundFinish();
	void RouteAssignBounty();
	MUID RecommendBounty();
public:
	MMatchRuleBounty(MMatchStage* pStage);
	virtual ~MMatchRuleBounty() { }
	virtual void* CreateRuleInfoBlob();
	virtual void OnEnterBattle(MUID& uidChar);
	virtual void OnLeaveBattle(MUID& uidChar);
	virtual void OnGameKill(const MUID& uidAttacker, const MUID& uidVictim);
	virtual MMATCH_GAMETYPE GetGameType() { return MMATCH_GAMETYPE_BOUNTY; }
	MUID& GetBounty() { return m_uidBounty; }
};

#endif