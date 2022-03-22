#ifndef _ZRULE_DEATH_MATCH_H
#define _ZRULE_DEATH_MATCH_H

#include "ZRule.h"

/////////////////////////////////////////////////////////////////////////////////////////
class ZRuleSoloDeathMatch : public ZRule
{
public:
	ZRuleSoloDeathMatch(ZMatch* pMatch);
	virtual ~ZRuleSoloDeathMatch();
};
/////////////////////////////////////////////////////////////////////////////////////////
class ZRuleTeamDeathMatch : public ZRule
{
public:
	ZRuleTeamDeathMatch(ZMatch* pMatch);
	virtual ~ZRuleTeamDeathMatch();
};
/////////////////////////////////////////////////////////////////////////////////////////
class ZRuleTeamDeathMatch2 : public ZRule
{
public:
	ZRuleTeamDeathMatch2(ZMatch* pMatch);
	virtual ~ZRuleTeamDeathMatch2();

	virtual bool OnCommand(MCommand* pCommand);
};
/////////////////////////////////////////////////////////////////////////////////////////
class ZRuleTeamCTF : public ZRule
{
private:
	void AssignFlagEffect(MUID& uidOwner, int nTeam);
public:
	ZRuleTeamCTF(ZMatch* pMatch);
	virtual ~ZRuleTeamCTF();
	MUID m_uidRedFlagHolder;
	MUID m_uidBlueFlagHolder;
	rvector m_BlueFlagPos;
	rvector m_RedFlagPos;
	int m_bRedFlagTaken;
	int m_bBlueFlagTaken;
	inline void SetBlueFlagState(int nState) { m_bBlueFlagTaken = nState; }
	inline void SetRedFlagState(int nState) { m_bRedFlagTaken = nState; }
	inline void SetBlueFlagPos(rvector newvector) { m_BlueFlagPos = newvector; }
	inline void SetRedFlagPos(rvector newvector) { m_RedFlagPos = newvector; }
	inline int GetBlueFlagState() { return m_bBlueFlagTaken; }
	inline int GetRedFlagState() { return m_bRedFlagTaken; }
	inline rvector GetBlueFlagPos() { return m_BlueFlagPos; }
	inline rvector GetRedFlagPos() { return m_RedFlagPos; }
	virtual bool OnCommand(MCommand* pCommand);
	inline void SetBlueCarrier(MUID state) { m_uidBlueFlagHolder = state; }
	inline void SetRedCarrier(MUID state) { m_uidRedFlagHolder = state; }
	inline MUID GetBlueCarrier() { return m_uidBlueFlagHolder; }
	inline MUID GetRedCarrier() { return m_uidRedFlagHolder; }
};
/////////////////////////////////////////////////////////////////////////////////////////
class ZRuleTeamEscape:  public ZRule
{
private:
	void HitEscapePortal(MUID& uidOwner, int nTeam);
public:
	ZRuleTeamEscape(ZMatch* pMatch);
	virtual ~ZRuleTeamEscape();
	virtual bool OnCommand(MCommand* pCommand);

	// MUID
	MUID m_uidBlueEscape;
	MUID m_uidRedEscape;

	// Functions
	virtual bool OnEscapePortalTeam(MCommand* pCommand);
	virtual bool OnEscapePortalState(MCommand* pCommand);
	virtual bool OnEscapePortalHit(MCommand* pCommand);
	virtual bool OnEscapePortalEffect(MCommand* pCommand);

	// Get / Set Functions
	inline MUID GetBlueEscapeChar() { return m_uidBlueEscape; }
	inline MUID GetRedEscapeChar() { return m_uidRedEscape; }

};

#endif