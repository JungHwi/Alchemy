#include "GameObject.h"
#include "Layer/GameLayer.h"

GameObject::GameObject(const char* name, CCSpriteBatchNode* pBatchNode, int zOrder) {
	m_pBatchNode = pBatchNode;
	m_winSize = CCDirector::sharedDirector()->getWinSize();
	m_name = name;
}

GameObject::~GameObject() {

}

// GET / SET Function.


string GameObject::GetName() {
	return m_name;
}

void GameObject::SetName(string name) {
	m_name = name;
}

void GameObject::SetGameLayer(GameLayer* pGameLayer) {
	m_pGameLayer = pGameLayer;
}


