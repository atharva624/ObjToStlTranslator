#include "STLWriter.h"
#include <fstream>
#include <iostream>

STLWriter::STLWriter(const std::string& outputFilePath) : outputFilePath(outputFilePath) {}

void STLWriter::writeSTL(const std::vector<Triangle>& triangles) {
    std::ofstream stlFile(outputFilePath);
    if (!stlFile) {
        std::cerr << "Failed to create STL file: " << outputFilePath << std::endl;
        return;
    }

    stlFile << "solid obj_to_stl\n";
    for (const auto& tri : triangles) {
        stlFile << "facet normal 0.0 0.0 0.0\n";
        stlFile << "  outer loop\n";
        stlFile << "    vertex " << tri.v1.x << " " << tri.v1.y << " " << tri.v1.z << "\n";
        stlFile << "    vertex " << tri.v2.x << " " << tri.v2.y << " " << tri.v2.z << "\n";
        stlFile << "    vertex " << tri.v3.x << " " << tri.v3.y << " " << tri.v3.z << "\n";
        stlFile << "  endloop\n";
        stlFile << "endfacet\n";
    }
    stlFile << "endsolid obj_to_stl\n";
}
