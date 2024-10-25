#pragma once
#include <string>
#include <vector>
#include "Vertex.h"
#include "Triangle.h"

class OBJReader {
public:
    OBJReader(const std::string& filePath);
    std::vector<Vertex> getVertices() const;
    std::vector<Triangle> getTriangles() const;

private:
    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;
    void parseOBJ(const std::string& filePath);
};
