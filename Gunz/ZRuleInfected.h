#ifndef _ZRULE_INFECTED_H
#define _ZRULE_INFECTED_H

#include "ZRule.h"


class ZRuleInfected : public ZRule
{
private:
	MUID m_uidZombieKing;
	void AssignZombieKing(MUID& uidZombieKing);
	void SetTeamClassify(MUID& uidZombieKing);

public:
	ZRuleInfected(ZMatch* pMatch);
	virtual ~ZRuleInfected();
	virtual void OnDrawZombieKing(MDrawContext* pDC);
	MUID GetZombieKingUID() const { return m_uidZombieKing; }
};

#endif