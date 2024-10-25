#pragma once
#include <string>
#include <vector>
#include "Triangle.h"

class STLWriter {
public:
    STLWriter(const std::string& outputFilePath);
    void writeSTL(const std::vector<Triangle>& triangles);

private:
    std::string outputFilePath;
};
