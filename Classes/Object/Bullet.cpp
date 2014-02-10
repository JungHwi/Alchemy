#include "Bullet.h"

Bullet::Bullet() {

}

Bullet::~Bullet() {

}
Bullet* Bullet::create(CCSpriteBatchNode* pBatchNode, int zOrder) {
	CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Bullet.png");

	Bullet* pBullet = new Bullet();
	if(pBullet && pBullet->initWithSpriteFrame(pFrame))	{
		pBatchNode->addChild(pBullet, zOrder);
		pBullet->autorelease();

		return pBullet;
	}

	CC_SAFE_DELETE(pBullet);

	return NULL;
}
