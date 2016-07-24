#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GameScene::init()
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

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(centerScreen);
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	bird = new Bird(this);

	this->schedule(schedule_selector(GameScene::SpawnPipe), PIPE_SPAWN_FREQUENCY * visibleSize.width);
	        
    return true;
}

void GameScene::SpawnPipe(float dt)
{
	pipe.SpawnPipe(this);
}