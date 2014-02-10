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

	// �����̱� ���� ��ǥ
	int m_prevBoardX;
	int m_prevBoardY;

	// ������ �� ���ؾ� �� ��ǥ
	int m_targetBoardX;
	int m_targetBoardY;

	GameLayer* m_pGameLayer;
};

#endif
