#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	// Grab the screen size and the origin of the screen
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 centerScreen = ((Vec2)visibleSize / 2.0f) + origin;


	auto backgroundSprite = Sprite::create("Background.png");
	backgroundSprite->setPosition(centerScreen);
	this->addChild(backgroundSprite);

	auto titleSprite = Sprite::create("title.png");
	titleSprite->setPosition(Vec2(centerScreen.x, visibleSize.height));
	this->addChild(titleSprite);

	auto playItem = MenuItemImage::create("Play Button.png", "Play Button Clicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
	playItem->setPosition(centerScreen);	
	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

    return true;
}
void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}