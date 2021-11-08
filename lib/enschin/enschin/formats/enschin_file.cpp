#include "enschin_file.h"

const std::string EnschinFile::encryptionKey = "abcd";

EnschinFile::EnschinFile(std::string filePath) {
    std::ifstream t(filePath);
    std::stringstream buffer;
    buffer << t.rdbuf();
    fileString = buffer.str();
}

void EnschinFile::encrypt() {

}

void EnschinFile::decrypt() {

}