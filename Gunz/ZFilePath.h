#ifndef _ZFILEPATH_H
#define _ZFILEPATH_H


#define FILENAME_TIPS					"localized/localize_english/tips.xml"
#define FILENAME_ZITEM_DESC				"localized/localize_english/zitem.xml"
#define FILENAME_ZITEM_DESC_LOCALE		"localized/localize_english/zitem_locale.xml"
#define FILENAME_BUFF_DESC				"localized/localize_english/zBuff.xml"
//#define FILENAME_ZITEMEFFECT_DESC		"localized/localize_english/zeffect.xml"
#define FILENAME_INTERFACE_MAIN			"main.xml"
#define FILENAME_ZNPC_DESC				"localized/localize_english/npc.xml"
#define FILENAME_ZSKILL_DESC			"localized/localize_english/zskill.xml"
#define FILENAME_SURVIVALMAP			"localized/localize_english/survivalmap.xml"
#define FILENAME_QUESTMAP				"localized/localize_english/questmap.xml"
#define FILENAME_QUESTITEM_DESC			"localized/localize_english/zquestitem.xml"
#define FILENAME_DROPTABLE				"localized/localize_english/droptable.xml"
#define FILENAME_CHATCMDS				"localized/localize_english/chatcmds.xml"
#define FILENAME_WORLDITEM				"localized/localize_english/worlditem.xml"
#define FILENAME_FILELIST				"localized/localize_english/filelist.xml"
#define FILENAME_SYSTEMMRS				"localized/localize_english.dev"
#define FILENAME_ABUSE					"localized/localize_english/abuse.txt"

#define MPATH_EMBLEMFOLDER				"/Emblem"
#define MPATH_EMBLEMFILE				"/emblem.xml"

// path는 마지막에 '/' 를 꼭 붙여줘야 한다.

#define	PATH_INTERFACE					"common/Interface/"
#define PATH_CUSTOM_CROSSHAIR			"custom/crosshair/"
#define PATH_GAME_MAPS					"maps/"
#define PATH_QUEST						"common/quest_mat/"
#define PATH_QUEST_MAPS					"common/quest_data/"
#define PATH_QUEST_CHALLENGE_MAPS		"common/quest_data/Challenge/Maps/"

// 마지막에 /를 붙이지 않음. ZLanguageConf클래스에서 커리해줌.
const char CLI_LANG_DIR[]					= "lang";
const char CLI_MESSAGE_TYPE[]				= "message";
const char CLI_ERRMESSAGE_TYPE[]			= "cserror";
const char CLI_MESSAGE_FILE_NAME[]			= "messages.xml";
const char CLI_ERROR_MESSAGE_FILE_NAME[]	= "cserror.xml";
/////////////////////////////////////////////////////////////







#endif