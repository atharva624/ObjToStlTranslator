#pragma once
#include "Vertex.h"

class Triangle {
public:
    Vertex v1, v2, v3;
    Triangle(const Vertex& vertex1, const Vertex& vertex2, const Vertex& vertex3)
        : v1(vertex1), v2(vertex2), v3(vertex3) {}
};
