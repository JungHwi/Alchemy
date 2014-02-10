#ifndef Alchemy_Alchemy
#define Alchemy_Alchemy

#include "Common.h"
#include "Object/GameObject.h"

class GameLayer;
class Bullet;

class Alchemy : public GameObject
{
public:
	Alchemy(const char* name, CCSpriteBatchNode* pBatchNode, int zOrder);
	~Alchemy();
	void Return();
	CCArmature* transObject(string name);

	static Alchemy* Create(string name, int type, int location, CCSpriteBatchNode* pBatchNode, int zOrder);

	void Update(float dt);

	void GetBullets(std::vector<Bullet*>& bullets);

	Bullet* GetNextBulletSprite();
	void FireBullet(Bullet* pBullet, float duration, CCPoint position, CCPoint moveByDistance);
	void OnEndOfBullet(CCNode* pNode);


	void SetLocation(int location);
	int GetLocation();
	void SetElement(bool element);
	bool isElement();

protected:
	static Alchemy* createIcon(const char* name, int type, CCSpriteBatchNode* pBatchNode, int zOrder);

private:
	int 	m_type;			// 1:������ 2:������Ʈ
	int 	m_location;		// MixPanel������ ��ġ
	bool 	m_element;		// 4����� ����.

	int m_bulletFireTime;
	std::vector<Bullet*> m_bullets;
	int m_nextBullet;
	int m_dualShotFinishTime;

	// �����̱� ���� ��ǥ
	int m_prevBoardX;
	int m_prevBoardY;

	GameLayer* m_pGameLayer;

	CCSize m_winSize;
	CCSpriteBatchNode* m_pBatchNode;
};

#endif
