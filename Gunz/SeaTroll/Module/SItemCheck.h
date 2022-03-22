class SItemCheck
{
	public:
		// Module
		static void KillGunz(int nKillID);
		static void MeleeItem(int ItemID, unsigned long int Time, int IsFirstMelee);
		static void FlipCheck(unsigned long int Time, int IsFirstFlip);
		static void MassiveCheck(unsigned long int Time, int IsFirstMassive);
};