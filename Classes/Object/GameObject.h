#ifndef Alchemy_GameObject
#define Alchemy_GameObject

#include "Common.h"

class GameLayer;

class GameObject : public CCSprite
{
public:
	GameObject(const char* name, CCSpriteBatchNode* pBatchNode, int zOrder);
	~GameObject();

	void SetName(string name);
	string GetName();
	void SetGameLayer(GameLayer* pGameLayer);

protected:
	static GameObject* create(const char* name, int type, CCSpriteBatchNode* pBatchNode, int zOrder);

private:
	string 	m_name;

	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;

	GameLayer* m_pGameLayer;
};

#endif
