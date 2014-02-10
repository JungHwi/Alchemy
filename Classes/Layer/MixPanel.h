#ifndef Alchemy_MixPanel
#define Alchemy_MixPanel

#include "Common.h"

class Alchemy;
class Item;

class MixPanel : public CCLayer
{
public:
	Alchemy* m_pAlchemy1;
	Alchemy* m_pAlchemy2;
	Alchemy* m_pMixPanel[OBJECT_COUNT];

	Alchemy* getGameObject(CCPoint point);
	void ProcesseMix();
	string SearchMix();

	bool init();
	void PrepareResources();
	static CCScene* scene();
	void ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent);
	void ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent);
	void ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent);

	CREATE_FUNC(MixPanel);

private:
	int m_clickTime;
	bool m_clicked;



	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;
	CCSprite* m_pBackground;
};

#endif
