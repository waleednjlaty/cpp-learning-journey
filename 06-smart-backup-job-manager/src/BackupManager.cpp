#include "include/BackupManager.hpp"
#include "include/FileService.hpp"
#include <iostream>
void BackupManager::createJob()
{
    std::string origiPath;
    std::string targPath;

    printf("Please Enter Original File Path: ");
    std::cin >> origiPath;
    printf("Please Enter Target File Path: ");
    std::cin >> targPath;
    auto newOb = std::make_shared<BackupJob>(nextId, origiPath, targPath);
    jobs.push_back(newOb);
    nextId++;
}
void BackupManager::showPendingJobs() const
{
    if (jobs.empty())
    {
        printf("no any Jobs\n");
        return;
    }
    for (size_t i = 0; i < jobs.size(); i++)
    {
        if (jobs[i]->getStatus() == "Pending")
        {
            jobs[i]->print();
        }
    }
}
void BackupManager::runJob()
{
    showPendingJobs();
    int select;
    printf("SelectJob Namber :");
    std::cin >> select;
    if (jobs[select - 1]->getStatus() == "Pending")
    {
        FileService fileService;

        if (fileService.copyFile(jobs[select - 1]->getOriginalPath(), jobs[select - 1]->getTargetPath()))
        {
            jobs[select - 1]->setStatus("Completed");
        }
        else
        {
            jobs[select - 1]->setStatus("Failed");
        }
    }
    else
    {
        printf("This Job is not Pending\n");
        return;
    }
}
void BackupManager::showCompletedJobs() const
{
    if (jobs.empty())
    {
        printf("no any Jobs\n");
        return;
    }
    for (size_t i = 0; i < jobs.size(); i++)
    {
        if (jobs[i]->getStatus() == "Completed")
        {
            jobs[i]->print();
        }
    }
}
void BackupManager::showJobsNam() const
{
    for (size_t i = 0; i < jobs.size(); i++)
    {
        printf("Job #%d\n", jobs[i]->getId());
    }
}
void BackupManager::showJobDetails() const
{
    showJobsNam();
    printf("======================================\nPlease Select Job Namber");
    u_int Index;
    std::cin >> Index;
    printf("===========================\n");
    jobs[Index - 1]->print();
}
void BackupManager::deleteJob()
{
    showJobsNam();
    printf("======================================\nPlease Select Job Namber");
    u_int Index;
    std::cin >> Index;
    printf("===========================\n");
    for (size_t i = 0; i < jobs.size(); i++)
    {
        if (jobs[i]->getId() == Index)
        {
            auto it = jobs.begin() + (Index - 1);
            jobs.erase(it);
        }
    }
}
void BackupManager::showOwnershipInfo() const
{
    showJobsNam();
    printf("======================================\nPlease Select Job Namber");
    u_int Index;
    std::cin >> Index;
    printf("===========================\n");
    std::cout << jobs[Index - 1].use_count() << "\n";
}