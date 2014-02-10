#ifndef Alchemy_Bullet
#define Alchemy_Bullet

#include "Common.h"

class Bullet : public CCSprite {
public:
	Bullet();
	~Bullet();
	static Bullet* create(CCSpriteBatchNode* pBatchNode, int zOrder);
	//static Bullet* Create(string bulletName, float width, float height);

protected:
	//static Bullet* create(const char* pszFileName, const CCRect& rect);

private:
	CCSpriteBatchNode* m_pBatchNode;
};


#endif
