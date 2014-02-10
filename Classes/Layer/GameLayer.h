#ifndef Alchemy_GameLayer
#define Alchemy_GameLayer

#include "Common.h"

class GameLayer : public CCLayer
{
public:
	bool init();

	static CCScene* scene();
	CREATE_FUNC(GameLayer);

protected:
	UILayer *m_pUiLayer;
	Layout *m_pWidget;

private:
	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;
};

#endif
