#pragma once
#include <string>
#include "enschin_file.h"

class ModelFile : public EnschinFile{
private:
    virtual void load() override;
public:
    ModelFile(std::string filePath) : EnschinFile(filePath){ load(); }
};