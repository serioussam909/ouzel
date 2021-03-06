// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "utils/Types.h"
#include "utils/Noncopyable.h"

namespace ouzel
{
    class Engine;
    
    class Cache: public Noncopyable
    {
        friend Engine;
    public:
        virtual ~Cache();

        void preloadTexture(const std::string& filename, bool dynamic = false, bool mipmaps = true);
        graphics::TexturePtr getTexture(const std::string& filename, bool dynamic = false, bool mipmaps = true) const;
        void setTexture(const std::string& filename, const graphics::TexturePtr& texture);
        void releaseTextures();

        void preloadSpriteFrames(const std::string& filename, bool mipmaps = true);
        std::vector<scene::SpriteFramePtr> getSpriteFrames(const std::string& filename, bool mipmaps = true) const;
        void setSpriteFrames(const std::string& filename, const std::vector<scene::SpriteFramePtr>& frames);
        void releaseSpriteFrames();

        graphics::ShaderPtr getShader(const std::string& shaderName) const;
        void setShader(const std::string& shaderName, const graphics::ShaderPtr& shader);

        void preloadParticleDefinition(const std::string& filename);
        scene::ParticleDefinitionPtr getParticleDefinition(const std::string& filename) const;

        graphics::BlendStatePtr getBlendState(const std::string& blendStateName) const;
        void setBlendState(const std::string& blendStateName, const graphics::BlendStatePtr& blendState);

    protected:
        Cache();

        mutable std::unordered_map<std::string, graphics::TexturePtr> textures;
        mutable std::unordered_map<std::string, graphics::ShaderPtr> shaders;
        mutable std::unordered_map<std::string, scene::ParticleDefinitionPtr> particleDefinitions;
        mutable std::unordered_map<std::string, graphics::BlendStatePtr> blendStates;
        mutable std::unordered_map<std::string, std::vector<scene::SpriteFramePtr>> spriteFrames;
    };
}
