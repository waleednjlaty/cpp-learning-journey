#pragma once

#include <vector>
#include <memory>
#include "BackupJob.hpp"

class BackupManager
{
private:
    std::vector<std::shared_ptr<BackupJob>> jobs;

    int nextId = 1;

public:
    void createJob();

    void showPendingJobs() const;

    void showJobsNam() const;

    void runJob();

    void showCompletedJobs() const;

    void showJobDetails() const;

    void deleteJob();

    void showOwnershipInfo() const;
};