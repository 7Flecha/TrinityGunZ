/*
modified by : 정동섭 @ 2006/3/16
	define->const enum으로 변경
	ZACTION_USE_WEAPON 추가
*/


#ifndef ZACTIONDEF_H
#define ZACTIONDEF_H

// 0 ~ 255
// 코드의 효율상, Action ID는 순차적으로 증가해야 한다.
// ZConfiguration.cpp의 초기 테이블(DefaultActionKeys)에 추가해야 한다.
const enum
{
	ZACTION_USE_WEAPON = 0,
	ZACTION_USE_WEAPON2,

	ZACTION_PREV_WEAPON,
	ZACTION_NEXT_WEAPON,

	ZACTION_FORWARD,
	ZACTION_BACK,
	ZACTION_LEFT,
	ZACTION_RIGHT,
	ZACTION_MELEE_WEAPON,
	ZACTION_PRIMARY_WEAPON,
	ZACTION_SECONDARY_WEAPON,
	ZACTION_ITEM1,
	ZACTION_ITEM2,
	ZACTION_COMMUNITYITEM1,
	ZACTION_COMMUNITYITEM2,

	ZACTION_RELOAD,
	ZACTION_JUMP,
	ZACTION_SCORE,
	ZACTION_MENU,
	
	ZACTION_TAUNT,
	ZACTION_BOW,
	ZACTION_WAVE,
	ZACTION_LAUGH,
	ZACTION_CRY,
	ZACTION_DANCE,
	
	ZACTION_SCREENSHOT,
	ZACTION_RECORD,
	ZACTION_MOVING_PICTURE,
	
	ZACTION_DEFENCE,
	ZACTION_TOGGLE_CHAT,

	ZACTION_SENSITIVITY_DEC,
	ZACTION_SENSITIVITY_INC,

	ZACTION_COUNT,
};

//#define ZACTION_FORWARD				0
//#define ZACTION_BACK				1
//#define ZACTION_LEFT				2
//#define ZACTION_RIGHT				3
//#define ZACTION_MELEE_WEAPON		4
//#define ZACTION_PRIMARY_WEAPON		5
//#define ZACTION_SECONDARY_WEAPON	6
//#define ZACTION_ITEM1				7
//#define ZACTION_ITEM2				8
//#define ZACTION_PREV_WEAPON			9
//#define ZACTION_NEXT_WEAPON			10
//#define ZACTION_RELOAD				11
//#define ZACTION_JUMP				12
//#define ZACTION_SCORE				13
//#define ZACTION_MENU				14
//
//#define ZACTION_TAUNT				15
//#define ZACTION_BOW					16
//#define ZACTION_WAVE				17
//#define ZACTION_LAUGH				18
//#define ZACTION_CRY					19
//#define ZACTION_DANCE				20
//
//#define ZACTION_SCREENSHOT			21
//#define ZACTION_RECORD				22
//
//#define ZACTION_DEFENCE				23
//
//#define ZACTION_TOGGLE_CHAT			24
//
//#define ZACTION_COUNT				25	// Count

#endif