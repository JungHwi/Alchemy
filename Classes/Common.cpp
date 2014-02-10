#include "Common.h"

int Common::GetCurrentTimeInMilli()
{
    timeval time;
    gettimeofday(&time, NULL);

    unsigned long millisecs = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return millisecs;
}

std::string Common::GetFileName(const char* name, int type){
	std::string result = "";
	switch(type){
		case ICON:
			result.append("i");
			break;
		case ALCHEMY:
			result.append("o");
			break;
		default:
			CCLog("Common::GetFileName Type Check : >%d<", type);
	}

	result.append(name);
	result.append(".png");
	CCLog("GetFileName >%s<", result.c_str());
	return result;
}

float Common::ComputeX(float x) {
	return floorf(x * BOARD_WIDTH + 130.0f) ;
}

float Common::ComputeY(float y) {
	//return CCDirector::sharedDirector()->getWinSize().height - floorf(y * BOARD_HEIGHT + 710.0f);
	return floorf(y * BOARD_HEIGHT + 705.0f);
}

CCPoint Common::ComputeXY(float x, float y) {
	return ccp(ComputeX(x), ComputeY(y));
}

int Common::ComputeBoardX(float x) {
	return (int)((x - 48.0f) / floorf(BOARD_WIDTH));
}

int Common::ComputeBoardY(float y) {
	return (int)((y - 690.0f) / floorf(BOARD_HEIGHT));  //
}
