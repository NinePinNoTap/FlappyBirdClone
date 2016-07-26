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

	cocos2d::PhysicsWorld *sceneWorld;
	Pipe pipe;
	Bird* bird;
};