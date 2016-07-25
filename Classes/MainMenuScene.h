#pragma once

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // Implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

private:
	void GoToGameScene(cocos2d::Ref* sender);

};