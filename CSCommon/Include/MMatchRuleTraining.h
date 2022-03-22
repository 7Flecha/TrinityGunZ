#ifndef _MMATCHRULE_TRAINING_H
#define _MMATCHRULE_TRAINING_H


#include "MMatchRuleDeathMatch.h"

///////////////////////////////////////////////////////////////////////////////////////////////
class MMatchRuleTraining : public MMatchRuleSoloDeath {
public:
	MMatchRuleTraining(MMatchStage* pStage);
	virtual ~MMatchRuleTraining()	{ }
	virtual MMATCH_GAMETYPE GetGameType() { return MMATCH_GAMETYPE_TRAINING; }
};

///////////////////////////////////////////////////////////////////////////////////////////////
class MMatchRuleTeamTraining : public MMatchRule {
protected:
	bool GetAliveCount(int* pRedAliveCount, int* pBlueAliveCount);
	virtual void OnBegin();
	virtual void OnEnd();
	virtual bool OnRun();
	virtual void OnRoundBegin();
	virtual void OnRoundEnd();
	virtual bool OnCheckRoundFinish();
	virtual void OnRoundTimeOut();
	virtual bool RoundCount();
	virtual bool OnCheckEnableBattleCondition();
public:
	MMatchRuleTeamTraining(MMatchStage* pStage);
	virtual ~MMatchRuleTeamTraining()				{}
	virtual void CalcTeamBonus(MMatchObject* pAttacker, MMatchObject* pVictim, int nSrcExp, int* poutAttackerExp, int* poutTeamExp);
	virtual MMATCH_GAMETYPE GetGameType() { return MMATCH_GAMETYPE_TRAINING_TEAM; }
};





#endif