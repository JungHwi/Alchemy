#ifndef Alchemy_Item
#define Alchemy_Item

#include "Common.h"

class GameLayer;

class Item : public GameObject
{
public:
	Item();
	~Item();

protected:
	static Item* create(const char* pszFileName, const CCRect& rect);

public:
	static Item* Create(int type);

	void SetGameLayer(GameLayer* pGameLayer);

private:
	int m_type;

	// 움직이기 전의 좌표
	int m_prevBoardX;
	int m_prevBoardY;

	// 움직일 때 향해야 할 좌표
	int m_targetBoardX;
	int m_targetBoardY;

	GameLayer* m_pGameLayer;
};

#endif
