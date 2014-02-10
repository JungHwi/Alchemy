#include "GameLayer.h"
#include "Field.h"
#include "MixPanel.h"
#include "UI.h"

bool GameLayer::init() {
	if(CCLayer::init() == false) {
		return false;
	}

	return true;
}

CCScene* GameLayer::scene(){
	CCScene* pScene = CCScene::create();

	GameLayer* pGameLayer = GameLayer::create();
	pScene->addChild(pGameLayer, 0);

	MixPanel* pMixPanel = MixPanel::create();
	pMixPanel->setContentSize(ccp(1080.0f, 441.0f));
	pScene->addChild(pMixPanel, 2);

	Field* pField = Field::create();
	pField->SetMixPanel(pMixPanel);
	pScene->addChild(pField, 1);

	UI* pUI = UI::create();
	pScene->addChild(pUI,3);

	return pScene;
}

