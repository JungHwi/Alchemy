#ifndef Alchemy_UI
#define Alchemy_UI

#include "Common.h"

class UI : public CCLayer
{
public:
    bool init();

    static CCScene* scene();

    CREATE_FUNC(UI);

protected:
    UILayer *m_pUiLayer;
    Layout *m_pWidget;
};

#endif
