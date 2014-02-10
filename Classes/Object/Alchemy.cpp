#include "Alchemy.h"
#include "Bullet.h"
#include "Layer/GameLayer.h"

Alchemy::Alchemy(const char* name, CCSpriteBatchNode* pBatchNode, int zOrder):GameObject(name, pBatchNode, zOrder) {
	m_pBatchNode = pBatchNode;
	m_winSize = CCDirector::sharedDirector()->getWinSize();

	m_nextBullet = 0;
	m_bulletFireTime = Common::GetCurrentTimeInMilli();
	m_dualShotFinishTime = Common::GetCurrentTimeInMilli();
	for(int i = 0; i < NUM_OF_CACHED_BULLETS; ++i) {
		Bullet* pBullet = Bullet::create(pBatchNode, zOrder);
		pBullet->setVisible(false);
		m_bullets.push_back(pBullet);
	}
}

Alchemy::~Alchemy() {

}


Alchemy* Alchemy::createIcon(const char* name, int type, CCSpriteBatchNode* pBatchNode, int zOrder) {
	CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(Common::GetFileName(name, type).c_str());

	Alchemy* pAlchemy = new Alchemy(name, pBatchNode, zOrder);
	if(pAlchemy && pAlchemy->initWithSpriteFrame(pFrame)){
		pAlchemy->setAnchorPoint(ccp(0.5f, 0.5f));
		pBatchNode->addChild(pAlchemy, zOrder);
		pAlchemy->autorelease();
		return pAlchemy;
	}

	CC_SAFE_DELETE(pAlchemy);

	return NULL;
}

Alchemy* Alchemy::Create(string name, int type, int location, CCSpriteBatchNode* pBatchNode, int zOrder) {
	Alchemy* pAlchemy = NULL;
	pAlchemy = Alchemy::createIcon(name.c_str(), type, pBatchNode, zOrder);
	pAlchemy->SetName(name);
	pAlchemy->SetLocation(location);

	return pAlchemy;
}

void Alchemy::Return() {

}

CCArmature* Alchemy::transObject(string name) {
	string abc = GetName();
	string pngPath = "Alchemy/" + name + "/" + name + "0.png";
	string plistPath = "Alchemy/" + name + "/" + name + "0.plist";
	string jsonPath = "Alchemy/" + name + "/" + name + ".ExportJson";
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(pngPath.c_str(), plistPath.c_str(), jsonPath.c_str());
	CCArmature* armature = CCArmature::create(name.c_str());
	return armature;
}

void Alchemy::Update(float dt) {
	if(isVisible() == false) {
		return;
	}
	int currentTime = Common::GetCurrentTimeInMilli();

	if(m_bulletFireTime + BULLET_FIRE_COOLTIME <= currentTime) {
		if(m_dualShotFinishTime > Common::GetCurrentTimeInMilli()){
			Bullet* pBullet = GetNextBulletSprite();
			CCSize bulletSize = pBullet->getContentSize();
			FireBullet(pBullet, 1.5f, ccpAdd(getPosition(), ccp(-bulletSize.width * 0.5f, getContentSize().height * 0.5f)), ccp(0.0f, m_winSize.height));
			pBullet = GetNextBulletSprite();
			FireBullet(pBullet, 1.5f, ccpAdd(getPosition(), ccp(+bulletSize.width * 0.5f, getContentSize().height * 0.5f)), ccp(0.0f, m_winSize.height));
		} else {
			Bullet* pBullet = GetNextBulletSprite();
			FireBullet(pBullet, 1.5f, ccpAdd(getPosition(), ccp(0.0f, getContentSize().height*0.5f)), ccp(0.0f, m_winSize.height));
		}
		m_bulletFireTime = currentTime;
	}
}

void Alchemy::GetBullets(std::vector<Bullet*>& bullets) {
	bullets = m_bullets;
}

void Alchemy::FireBullet(Bullet* pBullet, float duration, CCPoint position, CCPoint moveByDistance) {
	pBullet->setPosition(getPosition());
	pBullet->setVisible(true);
	pBullet->stopAllActions();

	CCCallFuncN* pCallFuncN = CCCallFuncN::create(this, callfuncN_selector(Alchemy::OnEndOfBullet));
	CCMoveBy* pMoveBy = CCMoveBy::create(duration, moveByDistance);
	pBullet->runAction(CCSequence::create(pMoveBy, pCallFuncN, NULL));
}

Bullet* Alchemy::GetNextBulletSprite() {
	Bullet* pBullet = m_bullets[m_nextBullet++];
	if(m_nextBullet >= m_bullets.size())
		m_nextBullet = 0;

	return pBullet;
}

void Alchemy::OnEndOfBullet(CCNode* pNode) {
	pNode->setVisible(false);
}

// GET / SET Function.
int Alchemy::GetLocation() {
	return m_location;
}

void Alchemy::SetLocation(int location) {
	m_location = location;
}

bool Alchemy::isElement(){
	if(!this->GetName().compare("Fire") || !this->GetName().compare("Wind") || !this->GetName().compare("Water") || !this->GetName().compare("Earth"))
		return true;

	return false;
}
