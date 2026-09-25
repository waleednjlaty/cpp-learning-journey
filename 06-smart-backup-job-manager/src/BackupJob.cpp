#include "include/BackupJob.hpp"
BackupJob::BackupJob(int id, const std::string &originalPath,
                     const std::string &targetPath)
{
    this->status = "Pending";
    this->size = 0;
    this->originalPath = originalPath;
    this->targetPath = targetPath;
    this->id = id;
}
void BackupJob::print() const
{
    printf("Job #%d\n", this->id);
    printf("Source: %s\n", this->originalPath.c_str());
    printf("Destination: %s\n", this->targetPath.c_str());
    printf("Status: %s\n", this->status.c_str());
    printf("Size: %d\n", this->size);
}
void BackupJob::setStatus(const std::string &newStatus)
{
    this->status = newStatus;
}
int BackupJob::getId() const
{
    return this->id;
}
int BackupJob::getSize() const
{
    return this->size;
}
const std::string &BackupJob::getOriginalPath() const
{
    return this->originalPath;
}
const std::string &BackupJob::getTargetPath() const
{
    return this->targetPath;
}
const std::string &BackupJob::getStatus() const
{
    return this->status;
}