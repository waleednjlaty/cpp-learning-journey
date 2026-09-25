#pragma once

#include <string>
#include <cstdint>

class FileService
{
public:
    bool fileExists(const std::string &path) const;

    bool copyFile(const std::string &source,
                  const std::string &destination) const;

    std::uintmax_t getFileSize(const std::string &path) const;
};