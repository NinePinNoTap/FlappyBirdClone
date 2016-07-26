#pragma once

#include "cocos2d.h"
#include "Bird.h"
#include "Pipe.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // Implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
	inline void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; }
	void SpawnPipe(float dt);

	bool onContactBegin(cocos2d::PhysicsContact &contact);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void StopFlying(float dt);
	void update(float dt);

	cocos2d::PhysicsWorld *sceneWorld;
	Pipe pipe;
	Bird* bird;
};