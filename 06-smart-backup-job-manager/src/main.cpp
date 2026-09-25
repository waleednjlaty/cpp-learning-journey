#include <iostream>
#include "include/BackupManager.hpp"

void menu()
{
    std::cout << "\n========== Smart Backup Job Manager ==========\n";
    std::cout << "1) Create Backup Job\n";
    std::cout << "2) Show Pending Jobs\n";
    std::cout << "3) Run Backup Job\n";
    std::cout << "4) Show Completed Jobs\n";
    std::cout << "5) Show Job Details\n";
    std::cout << "6) Delete Job\n";
    std::cout << "7) Show Ownership Info\n";
    std::cout << "8) Exit\n";
    std::cout << "==============================================\n";
    std::cout << "Choose an option: ";
}

int main()
{
    BackupManager manager;

    bool run = true;
    int choose;

    while (run)
    {
        menu();
        std::cin >> choose;

        switch (choose)
        {
        case 1:
            manager.createJob();
            break;

        case 2:
            manager.showPendingJobs();
            break;

        case 3:
            manager.runJob();
            break;

        case 4:
            manager.showCompletedJobs();
            break;

        case 5:
            manager.showJobDetails();
            break;

        case 6:
            manager.deleteJob();
            break;

        case 7:
            manager.showOwnershipInfo();
            break;

        case 8:
            run = false;
            break;

        default:
            break;
        }
    }

    return 0;
}