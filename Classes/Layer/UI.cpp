#include "UI.h"

bool UI::init() {
	if (CCLayer::init()) {
		m_pUiLayer = UILayer::create();
		m_pUiLayer->scheduleUpdate();
		addChild(m_pUiLayer);

		// 상단 UI
		UIImageView* waveFrame = UIImageView::create();
		waveFrame->loadTexture("Layer/upui/upuiframe.png");
		waveFrame->setAnchorPoint(ccp(0.0f, 1.0f));
		waveFrame->setPosition(ccp(0.0f, 1920.0f));
		waveFrame->setZOrder(0);
		m_pUiLayer->addWidget(waveFrame);

		UIImageView* wave = UIImageView::create();
		wave->loadTexture("Layer/gauge/back.png");
		wave->setAnchorPoint(ccp(0.0f, 0.0f));
		wave->setPosition(ccp(0.0f, 450.0f));
		wave->setZOrder(0);
		m_pUiLayer->addWidget(wave);

		UIImageView* stageFrame = UIImageView::create();
		stageFrame->loadTexture("Layer/upui/upuiframe.png");
		stageFrame->setAnchorPoint(ccp(0.0f, 1.0f));
		stageFrame->setPosition(ccp(500.0f, 1920.0f));
		stageFrame->setZOrder(0);
		m_pUiLayer->addWidget(stageFrame);

		UIButton* pauseBtn = UIButton::create();
		pauseBtn->setTouchEnabled(true);
		pauseBtn->loadTextures("Layer/upui/pauseon.png", "Layer/upui/pauseoff.png", "");
		pauseBtn->setAnchorPoint(ccp(1.0f, 1.0f));
		pauseBtn->setPosition(ccp(980.0f, 1920.0f));
		m_pUiLayer->addWidget(pauseBtn);

		UIButton* soundOBtn = UIButton::create();
		soundOBtn->setTouchEnabled(true);
		soundOBtn->loadTextures("Layer/upui/soundoon.png", "Layer/upui/soundooff.png", "");
		soundOBtn->setAnchorPoint(ccp(1.0f, 1.0f));
		soundOBtn->setPosition(ccp(1080.0f, 1920.0f));
		m_pUiLayer->addWidget(soundOBtn);

		UIButton* soundXBtn = UIButton::create();
		soundXBtn->setTouchEnabled(false);
		soundXBtn->setVisible(false);
		soundXBtn->loadTextures("Layer/upui/soundxon.png", "Layer/upui/soundxoff.png", "");
		soundXBtn->setAnchorPoint(ccp(1.0f, 1.0f));
		soundXBtn->setPosition(ccp(1080.0f, 1920.0f));
		m_pUiLayer->addWidget(soundXBtn);

		// 하단 UI
		UIImageView* back = UIImageView::create();
		back->loadTexture("Layer/gauge/back.png");
		back->setAnchorPoint(ccp(0.0f, 0.0f));
		back->setPosition(ccp(0.0f, 450.0f));
		back->setZOrder(0);
		m_pUiLayer->addWidget(back);

		UIImageView* frame = UIImageView::create();
		frame->loadTexture("Layer/gauge/frame.png");
		frame->setAnchorPoint(ccp(0.0f, 0.0f));
		frame->setPosition(ccp(0.0f, 450.0f));
		frame->setZOrder(1);
		m_pUiLayer->addWidget(frame);

		UIImageView* text = UIImageView::create();
		text->loadTexture("Layer/gauge/text.png");
		text->setAnchorPoint(ccp(0.0f, 0.0f));
		text->setPosition(ccp(0.0f, 450.0f));
		text->setZOrder(3);
		m_pUiLayer->addWidget(text);

		UILoadingBar* conbar = UILoadingBar::create();
		conbar->setName("conbar");
		conbar->setAnchorPoint(ccp(0.0f, 0.0f));
		conbar->setPosition(ccp(265.0f, 556.0f));
		conbar->loadTexture("Layer/gauge/conbar.png");
		conbar->setPercent(100);
		conbar->setZOrder(2);
		m_pUiLayer->addWidget(conbar);

		UILoadingBar* manabar = UILoadingBar::create();
		manabar->setName("manabar");
		manabar->setAnchorPoint(ccp(0.0f, 0.0f));
		manabar->setPosition(ccp(300.0f, 487.0f));
		manabar->loadTexture("Layer/gauge/manabar.png");
		manabar->setPercent(100);
		manabar->setZOrder(2);
		m_pUiLayer->addWidget(manabar);
		return true;
	}

	return false;
}

CCScene* UI::scene(){
	CCScene* pScene = CCScene::create();

	UI* pUI = UI::create();
	pScene->addChild(pUI, 1);

	return pScene;
}



