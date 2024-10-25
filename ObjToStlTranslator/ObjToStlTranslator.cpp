#include <iostream>
#include "OBJReader.h"
#include "STLWriter.h"

int main() {
    std::string inputFilePath = "D:/AtharvaWorkspace/Rough/cube.obj";
    std::string outputFilePath = "D:/AtharvaWorkspace/Rough/solid-cube.stl";

    OBJReader objReader(inputFilePath);
    STLWriter stlWriter(outputFilePath);

    // Get the triangles from the OBJ reader
    auto triangles = objReader.getTriangles();
    if (triangles.empty()) {
        std::cerr << "No triangles were created from the OBJ file." << std::endl;
        return 1;
    }

    // Write to STL
    stlWriter.writeSTL(triangles);
    return 0;
}
