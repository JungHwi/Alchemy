#ifndef Alchemy_Field
#define Alchemy_Field

#include "Common.h"

class GameObject;
class Alchemy;
class MixPanel;

class Field : public CCLayer
{
public:
	void StartGame();

	bool init();
	void update(float dt);

	static CCScene* scene();

	void SetMixPanel(MixPanel* pMixPanel);

	void ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent);
	void ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent);
	void ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent);

	CREATE_FUNC(Field);

private:
	Alchemy* m_pBoard[COLUMN_COUNT][ROW_COUNT];
	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;

	CCPoint m_prevTouchPos;
	CCSprite* m_pBackground;

	MixPanel* m_pMixPanel;
	UILayer* m_pUILayer;
};

#endif
