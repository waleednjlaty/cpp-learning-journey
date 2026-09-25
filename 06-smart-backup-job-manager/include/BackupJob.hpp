#pragma once

#include <string>

class BackupJob
{
private:
    int id;
    std::string originalPath;
    std::string targetPath;
    std::string status;
    int size;

public:
    BackupJob(int id,
              const std::string &originalPath,
              const std::string &targetPath);

    void print() const;

    void setStatus(const std::string &newStatus);

    int getId() const;
    const std::string &getOriginalPath() const;
    const std::string &getTargetPath() const;
    const std::string &getStatus() const;
    int getSize() const;
};