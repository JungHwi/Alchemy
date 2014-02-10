#include "MixPanel.h"
#include "Object/GameObject.h"
#include "Object/Alchemy.h"
#include "Util/rapidjson/document.h"
#include "Util/rapidjson/reader.h"

using namespace rapidjson;

bool MixPanel::init() {
	if(CCLayer::init() == false) {
		return false;
	}

	m_clickTime = 0;
	m_clicked = false;

	setTouchEnabled(true);
	PrepareResources();

	m_pBackground = CCSprite::create("Layer/lMixPanel.png");
	m_pBackground->setPosition(CCPointZero);
	m_pBackground->setAnchorPoint(ccp(0.0f, 0.0f));
	addChild(m_pBackground, Common::zBackground);

	m_winSize = CCDirector::sharedDirector()->getWinSize();

	m_pMixPanel[0] = Alchemy::Create("Fire", ICON, 0, m_pBatchNode, Common::zIcon);
	m_pMixPanel[0]->setPosition(ccp(221.0f, 352.0f));

	m_pMixPanel[1] = Alchemy::Create("Wind", ICON, 1, m_pBatchNode, Common::zIcon);
	m_pMixPanel[1]->setPosition(ccp(89.0f, 220.0f));

	m_pMixPanel[2] = Alchemy::Create("Water", ICON, 2, m_pBatchNode, Common::zIcon);
	m_pMixPanel[2]->setPosition(ccp(352.0f, 220.0f));

	m_pMixPanel[3] = Alchemy::Create("Earth", ICON, 3, m_pBatchNode, Common::zIcon);
	m_pMixPanel[3]->setPosition(ccp(221.0f, 97.0f));

	scheduleUpdate();

	return true;
}

Alchemy* MixPanel::getGameObject(CCPoint point) {
	for(int i=0; i < OBJECT_COUNT; i++) {
		if(m_pMixPanel[i] != NULL) {
			if(m_pMixPanel[i]->boundingBox().containsPoint(point)) {
				CCLog("getGameObject >%d< >%s<", i, m_pMixPanel[i]->GetName().c_str());
				return m_pMixPanel[i];
			}
		}
	}
	return NULL;
}

string MixPanel::SearchMix() {
	const char* name = "NOT RESULT";
	bool searchOK = false;
	Document document;

	string fileName = CCFileUtils::sharedFileUtils()->fullPathForFilename("Data/MixData.json");

	unsigned long bufferSize = 0;
	unsigned char* json = CCFileUtils::sharedFileUtils()->getFileData(fileName.c_str(), "rb", &bufferSize);

	string clearData((const char*)json);
	size_t pos = clearData.rfind("}");
	clearData = clearData.substr(0, pos+1);

	if(document.Parse<0>(clearData.c_str()).HasParseError()) {
		CCLog("Err..%s", document.Parse<0>(clearData.c_str()).GetParseError());
		return name;
	}

	const Value& a = document["MixData"];

	for(rapidjson::SizeType i = 0; i < a.Size(); i++) {
		if(!m_pAlchemy1->GetName().compare(a[i]["material1"].GetString())) {
			if(!m_pAlchemy2->GetName().compare(a[i]["material2"].GetString())) {
				name = a[i]["result"].GetString();
				searchOK = true;
			}
		}
	}

	if(!searchOK) {
		for(rapidjson::SizeType i = 0; i < a.Size(); i++) {
			if(!m_pAlchemy1->GetName().compare(a[i]["material2"].GetString())) {
				if(!m_pAlchemy2->GetName().compare(a[i]["material1"].GetString())) {
					name = a[i]["result"].GetString();
				}
			}
		}
	}

	string result = name;
	return result;
}

void MixPanel::ProcesseMix(){
	int i;
	CCPoint point;
	string name;

	// 조합식 찾기
	name = SearchMix();
	if(!name.compare("NOT RESULT")) {
		return;
	}
	// 재료템 삭제
	if(!m_pAlchemy1->isElement()) {
		m_pMixPanel[m_pAlchemy1->GetLocation()]->setVisible(false);
		m_pMixPanel[m_pAlchemy1->GetLocation()] = NULL;
	}

	if(!m_pAlchemy2->isElement()) {
		m_pMixPanel[m_pAlchemy2->GetLocation()]->setVisible(false);
		m_pMixPanel[m_pAlchemy2->GetLocation()] = NULL;
	}

	// 빈칸 찾기
	for(i=4; i<10; i++) {
		if(m_pMixPanel[i] == NULL)
			break;
	}

	m_pMixPanel[i] = Alchemy::Create(name, ICON, i, m_pBatchNode, Common::zIcon);
	CCLog("count %d", i);
	CCLog("m_pMixPanel[i]->GetName() %s", m_pMixPanel[i]->GetName().c_str());

	switch(i){
		case 4:
			point = ccp(536.0f, 309.0f);
			break;
		case 5:
			point = ccp(704.0f, 344.0f);
			break;
		case 6:
			point = ccp(872.0f, 309.0f);
			break;
		case 7:
			point = ccp(536.0f, 132.0f);
			break;
		case 8:
			point = ccp(704.0f, 97.0f);
			break;
		case 9:
			point = ccp(872.0f, 132.0f);
			break;
	}
	m_pMixPanel[i]->setPosition(point);
}

void MixPanel::PrepareResources() {

	m_pBatchNode = CCSpriteBatchNode::create("Alchemy/ICON.png");
	addChild(m_pBatchNode, Common::zBatchNode);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Alchemy/ICON.plist");
}

CCScene* MixPanel::scene(){
	CCScene* pScene = CCScene::create();

	MixPanel* pMixPanel = MixPanel::create();
	pScene->addChild(pMixPanel);

	return pScene;
}

// Touch Event
void MixPanel::ccTouchesBegan(CCSet* pTouches, CCEvent* pEvent) {
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
	CCPoint point = pTouch->getLocation();
	if(point.y > 441.0f)
		return;

	CCLog("MixPanel Began");

	m_pAlchemy1 = getGameObject(point);
}

void MixPanel::ccTouchesMoved(CCSet* pTouches, CCEvent* pEvent) {
	if(m_pAlchemy1 != NULL && m_pAlchemy1->GetLocation() >= 4) {
		CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
		CCPoint point = pTouch->getLocation();

		m_pAlchemy1->setPosition(point);
	}
}

void MixPanel::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent) {
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
	CCPoint point = pTouch->getLocation();

	if(point.y > 441.0f)
		return;

	CCLog("MixPanel Ended");
	m_pAlchemy2 = getGameObject(point);
	if(m_pAlchemy1 != NULL && m_pAlchemy2 != NULL)
		ProcesseMix();

	m_pAlchemy1 = NULL;
	m_pAlchemy2 = NULL;
}
