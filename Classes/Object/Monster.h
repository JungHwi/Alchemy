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
	int 	m_type;			// 1:������ 2:������Ʈ
	int 	m_location;		// MixPanel������ ��ġ
	bool 	m_element;		// 4����� ����.

	// �����̱� ���� ��ǥ
	int m_prevBoardX;
	int m_prevBoardY;

	GameLayer* m_pGameLayer;

	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;
};

#endif
