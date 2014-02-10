#ifndef Alchemy_Common
#define Alchemy_Common

#include "cocos2d.h"
#include "cocos-ext.h"

class Alchemy;

using namespace std;
USING_NS_CC;
USING_NS_CC_EXT;

#define DESIGN_WIDTH		1080.0f
#define DESIGN_HEIGHT		1920.0f

#define MIX_WIDTH			1080.0f
#define MIX_HEIGHT			441.0f

#define BOARD_WIDTH			164.0f
#define BOARD_HEIGHT		148.0f

#define OBJECT_WIDTH 		128.0f
#define OBJECT_HEIGHT 		128.0f

#define ELEMENT_COUNT		4
#define	ALCHEMY_COUNT		6
#define	ITEM_COUNT			4
#define OBJECT_COUNT		ELEMENT_COUNT + ALCHEMY_COUNT + ITEM_COUNT

#define ICON				1
#define ALCHEMY				2
#define MONSTER				3

#define ROW_COUNT			7
#define COLUMN_COUNT 		6
#define MAX_ROW_COUNT 		10

#define TYPE_COUNT 			4

#define NUM_OF_CACHED_BULLETS	3
#define BULLET_FIRE_COOLTIME	1500

class Common
{
public:

	static float ComputeX(float x);
	static float ComputeY(float y);
	static CCPoint ComputeXY(float x, float y);

	static int ComputeBoardX(float x);
	static int ComputeBoardY(float y);

    static int GetCurrentTimeInMilli();
    static string GetFileName(const char* name, int type);

    enum zOrder {
    	zBackground = 0,
    	zBatchNode,
    	zGameObject,
    	zUI,
    	zIcon,
    };
};

#endif
