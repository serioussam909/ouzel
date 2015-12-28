// Copyright (C) 2015 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <d3d11.h>
#include "MeshBuffer.h"

namespace ouzel
{
    class MeshBufferD3D11: public MeshBuffer
    {
    public:
        MeshBufferD3D11(Renderer* renderer);
        virtual ~MeshBufferD3D11();
        
        virtual bool initFromData(const std::vector<uint16_t>& indices, const std::vector<Vertex>& vertices) override;

        virtual bool uploadIndices(const std::vector<uint16_t>& indices) override;
        virtual bool uploadVertices(const std::vector<Vertex>& vertices) override;

        ID3D11Buffer* getIndexBuffer() const { return _indexBuffer; }
        ID3D11Buffer* getVertexBuffer() const { return _vertexBuffer; }

        UINT getIndexCount() const { return _indexCount; }

    protected:
        bool uploadData(ID3D11Buffer* buffer, const void* data, uint32_t size);

        ID3D11Buffer* _indexBuffer = nullptr;
        ID3D11Buffer* _vertexBuffer = nullptr;
        UINT _indexCount = 0;
    };
}
