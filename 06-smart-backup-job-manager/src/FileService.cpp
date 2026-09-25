#include "include/FileService.hpp"

#include <filesystem>

std::uintmax_t FileService::getFileSize(const std::string &path) const
{
    return std::filesystem::file_size(path);
}
bool FileService::copyFile(const std::string &source,
                           const std::string &destination) const
{
    return std::filesystem::copy_file(source, destination);
}
bool FileService::fileExists(const std::string &path) const
{

    return std::filesystem::exists(path);
}