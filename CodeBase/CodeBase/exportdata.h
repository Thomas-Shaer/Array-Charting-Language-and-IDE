#pragma once
#include <vector>
#include <memory>
#include <iostream>
class VarSymbol;

void exportColumnWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables);
void exportRowWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables);