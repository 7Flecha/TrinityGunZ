#ifndef _ZRULE_VAMPIREMODE_H
#define _ZRULE_VAMPIREMODE_H

#include "ZRule.h"

/////////////////////////////////////////////////////////////////////////////////////////
class ZRuleVampire : public ZRule
{
private:
	void ExtraHPAP(ZCharacter* pCharacter);
public:
	ZRuleVampire(ZMatch* pMatch);
	virtual ~ZRuleVampire();
	virtual bool OnCommand(MCommand* pCommand);
};

#endif