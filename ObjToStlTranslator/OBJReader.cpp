#include "OBJReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

OBJReader::OBJReader(const std::string& filePath) {
    parseOBJ(filePath);
}

void OBJReader::parseOBJ(const std::string& filePath) {
    std::ifstream objFile(filePath);
    if (!objFile) {
        std::cerr << "Failed to open .obj file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(objFile, line)) {
        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v ") {  // Parse vertex
            float x, y, z;
            if (ss >> x >> y >> z) {
                vertices.emplace_back(x, y, z);
            }
            else {
                std::cerr << "Malformed vertex line: " << line << std::endl;
            }
        }
        else if (type == "vn") {  // Parse normal (optional)
            float nx, ny, nz;
            if (ss >> nx >> ny >> nz) {
                // Optional: Store normals if needed, currently not used
            }
            else {
                std::cerr << "Malformed normal line: " << line << std::endl;
            }
        }
        else if (type == "f") {  // Parse face
            int v1, v2, v3;
            char slash1, slash2;
            if (ss >> v1 >> slash1 >> slash2 >> v2 >> slash1 >> slash2 >> v3) {
                if (v1 > 0 && v2 > 0 && v3 > 0 &&
                    v1 <= vertices.size() && v2 <= vertices.size() && v3 <= vertices.size()) {
                    triangles.emplace_back(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1]);
                }
                else {
                    std::cerr << "Face index out of range: " << v1 << ", " << v2 << ", " << v3
                        << " (Vertices count: " << vertices.size() << ")" << std::endl;
                }
            }
            else {
                std::cerr << "Malformed face line: " << line << std::endl;
            }
        }
    }
}

std::vector<Vertex> OBJReader::getVertices() const {
    return vertices;
}

std::vector<Triangle> OBJReader::getTriangles() const {
    return triangles;
}
