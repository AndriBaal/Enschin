#pragma once

#include "vec2.h"
#include "model.h"
#include "renderer.h"
#include "context.h"
#include "game_object.h"
#include "terrain.h"
#include "chunk.h"
#include "chunk_manager.h"
#include <box2d/box2d.h>

class ContactListener : public b2ContactListener {
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
};

class World {
private:
    b2World world = b2World({0, -10});
    ContactListener *contactListener = new ContactListener();
    std::vector<Terrain*> terrains;
    ChunkManager chunkManager;
public:
    World(Vec2 amountOfChunks, Vec2 chunkSizes = {10, 10}, Vec2 gravity = {0, -12.0f});
    ~World();
    unsigned int addTerrain(const UpdateContext& ctx, const TerrainDefinition* terrainDef, const Color* color, Vec2 positionOffSet = {0, 0});
    void removeTerrain(unsigned int id);
    b2World &getWorld() { return world; }
    void setGravity(Vec2 newGravity) { world.SetGravity(newGravity.toB2()); }
    Vec2 getGravity() { return world.GetGravity(); }
    const ChunkManager& getChunkManager() const { return chunkManager; }
};
