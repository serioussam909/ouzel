// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "ScaleTo.h"
#include "Node.h"

namespace ouzel
{
    ScaleTo::ScaleTo(float length, Vector2 const& scale):
        Animator(length), _targetScale(scale)
    {
        
    }
    
    void ScaleTo::start(NodePtr const& node)
    {
        Animator::start(node);
        
        if (node)
        {
            _startScale = node->getScale();
            _diff = _targetScale - _startScale;
        }
    }
    
    void ScaleTo::setProgress(float progress)
    {
        Animator::setProgress(progress);
        
        if (NodePtr node = _node.lock())
        {
            node->setScale(_startScale + (_diff * _progress));
        }
    }
}