// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <vector>
#include "animators/Animator.h"
#include "utils/Types.h"

namespace ouzel
{
    namespace scene
    {
        class Parallel: public Animator
        {
        public:
            Parallel(const std::vector<AnimatorPtr>& pAnimators);

            virtual void start(const NodePtr& targetNode) override;
            virtual void reset() override;

        protected:
            virtual void updateProgress() override;

            std::vector<AnimatorPtr> animators;
        };
    } // namespace scene
} // namespace ouzel
