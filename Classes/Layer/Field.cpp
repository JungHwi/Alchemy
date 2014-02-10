#include "Field.h"
#include "MixPanel.h"
#include "Object/Alchemy.h"

bool Field::init() {
	if(CCLayer::init() == false) {
		return false;
	}

	m_pUILayer = UILayer::create();
	m_pUILayer->scheduleUpdate();
	addChild(m_pUILayer);

	setTouchEnabled(true);

	m_pBackground = CCSprite::create("Layer/lBackground.png");
	m_pBackground->setPosition(ccp(0.0f, 321.0f));
	m_pBackground->setAnchorPoint(ccp(0.0f, 0.0f));

	addChild(m_pBackground, Common::zBackground);

	StartGame();
	scheduleUpdate();
	return true;
}

void Field::StartGame() {
	for(int x=0; x<COLUMN_COUNT; ++x){
		for(int y=0; y< ROW_COUNT; ++y) {
			m_pBoard[x][y] = NULL;
		}
	}
}

void Field::update(float dt) {
	for(int i=0; i<COLUMN_COUNT; i++) {
		for(int j=0; j<ROW_COUNT; j++) {
			if(m_pBoard[i][j]) {
				//CCLog("field update : %d, %d", i, j);
				m_pBoard[i][j]->Update(dt);
			}
		}
	}

}


// Touch Event
void Field::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent) {
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
	CCPoint point = pTouch->getLocation();

	if(pTouch->getLocation().y < 441.0f)
		return;

}

void Field::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent) {
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	if(pTouch->getLocation().y < 441.0f)
			return;

	//CCLog("Field Moved");
}

void Field::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent) {
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
	CCPoint point = pTouch->getLocation();
	if(pTouch->getLocation().y < 690.0f || pTouch->getLocation().y > 1726.0f || m_pMixPanel->m_pAlchemy1 == NULL)
		return;
	CCLog("Field Ended");

	m_pMixPanel->m_pMixPanel[m_pMixPanel->m_pAlchemy1->GetLocation()]->setVisible(false);
	m_pMixPanel->m_pMixPanel[m_pMixPanel->m_pAlchemy1->GetLocation()] = NULL;

	string action = "flame";
	int x = Common::ComputeBoardX(point.x);
	int y = Common::ComputeBoardY(point.y);
	m_pBoard[x][y] = m_pMixPanel->m_pAlchemy1;
//	m_pBoard[x][y]->setVisible(true);
//	CCArmature* pArmature = m_pBoard[x][y]->transObject(action);
//	pArmature->setAnchorPoint(ccp(0.5f, 0.0f));
//	pArmature->getAnimation()->playByIndex(2);
//	pArmature->setPosition(Common::ComputeXY(Common::ComputeBoardX(point.x), Common::ComputeBoardY(point.y)));
//	this->addChild(pArmature);

	try {
	for(int i=1; i<=20; i++) {
		for(int j=1; j<10; j++) {
			CCLog("%d %d", i, j);
			CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Alchemy/Flame/Flame0.png", "Alchemy/Flame/Flame0.plist" , "Alchemy/Flame/Flame.ExportJson");
			CCLog("1111");
			CCArmature* armature = CCArmature::create("Flame");
			CCLog("2222");
			armature->setAnchorPoint(ccp(0.5f, 0.0f));
			CCLog("3333 %d", i%2);
			armature->getAnimation()->playByIndex(i%2);
			CCLog("4444");
			armature->setPosition(1080*i/20, 1920*j/10);
			CCLog("5555 %d %d", 1080*i/20, 1920*j/10);
			this->addChild(armature);
			CCLog("6666");
		}
	}
	}catch(exception e) {

	}

}

CCScene* Field::scene(){
	CCScene* pScene = CCScene::create();

	Field* pField = Field::create();
	pScene->addChild(pField, 1);

	return pScene;
}

void Field::SetMixPanel(MixPanel* pMixPanel) {
	m_pMixPanel = pMixPanel;
}
