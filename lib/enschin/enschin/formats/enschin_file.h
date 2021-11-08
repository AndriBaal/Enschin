#pragma once
#include <bits/stdc++.h>
#include <fstream>
#include <string>

class EnschinFile {
protected:
    virtual void load() = 0;
private:
    const static std::string encryptionKey;
    std::string fileString;
public:
    EnschinFile(std::string filePath);
    void encrypt();
    void decrypt();
};