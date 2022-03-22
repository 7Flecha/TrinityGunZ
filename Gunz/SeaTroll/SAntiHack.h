class SAntiHack
{
public:

	// Bool
	static bool IsFirstMassive;
	static bool IsFirstFlip;
	static bool IsFirstMelee;
	static bool IsFirstChat;
	static int ItemID;

	// Anti Hack
	static void SetIsFirst();
	static void AddMassive(const MUID& attacker);
	static void AddFlip(const MUID& attacker);
	static void AddMelee(const MUID& attacker, const int ItemID);
	static void ZPostChat(char *szMsg, int nTeam, int nState, int nKey);

private:
	static void CheckMassive(unsigned long time, const MUID attacker);
	static void CheckFlip(unsigned long time, const MUID attacker);
	static void CheckMelee(unsigned long Time, const MUID attacker);
};
