#ifndef Alchemy_Monster
#define Alchemy_Monster

#include "Common.h"
#include "Object/GameObject.h"

class GameLayer;

class Monster : public GameObject
{
public:
	Monster(const char* name, CCSpriteBatchNode* pBatchNode, int zOrder);
	~Monster();
	void Return();

	static Monster* Create(string name, int type, int location, CCSpriteBatchNode* pBatchNode, int zOrder);

protected:
	static Monster* createIcon(const char* name, int type, CCSpriteBatchNode* pBatchNode, int zOrder);

private:
	int 	m_type;			// 1:아이콘 2:오브젝트
	int 	m_location;		// MixPanel에서의 위치
	bool 	m_element;		// 4대원소 여부.

	// 움직이기 전의 좌표
	int m_prevBoardX;
	int m_prevBoardY;

	GameLayer* m_pGameLayer;

	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;
};

#endif
