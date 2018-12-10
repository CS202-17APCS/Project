#include "Object.h"
class CLIGHT
{
public:
	CLIGHT(int TRs,int TGs)
	{
		TR = TRs;
		TG = TGs;
		red = false;
		green = true;
		Counttime = 0;
	}
	bool OnGreen()
	{
		if (Counttime == TG)
		{
			red = true;
			green = false;
			Counttime = 0;
			return false;
		}
		return true;
	}
	bool OnRed()
	{
		if (Counttime == TR)
		{
			red = false;
			green = true;
			Counttime = 0;
			return false;
		}
		return true;
	}
	void Increasetime()
	{
		Counttime++;
	}
	CLIGHT()
	{
		red = false;
		green = true;
	}
private:
	bool red;
	bool green;
	int TR;//Time settings for red duration
	int TG;//Time settings for green duration
	int Counttime;
};