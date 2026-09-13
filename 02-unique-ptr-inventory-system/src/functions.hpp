#include <string>
int getOption()
{
    int choice;

    while (true)
    {
        std::cin >> choice;

        if (!std::cin.fail())
        {
            return choice;
        }

        std::cout << "Invalid input. Please enter a number: ";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n');
    }
}

void createWeapon()
{
    std::cout
        << "\n=== Create Weapon ===\n"
        << "1. Rifle\n"
        << "2. Pistol\n"
        << "3. Knife\n"
        << "Choose a weapon type: ";

    int choice = getOption();

    while (choice < 1 || choice > 3)
    {
        std::cout << "Invalid option. Please choose between 1 and 3: ";
        choice = getOption();
    }

    if (choice == 1)
    {
        auto weapon = std::make_unique<Rifle>("Rifle");
        inventory.push_back(std::move(weapon));
    }
    else if (choice == 2)
    {
        auto weapon = std::make_unique<Pistol>("Pistol");
        inventory.push_back(std::move(weapon));
    }
    else
    {
        auto weapon = std::make_unique<Knife>("Knife");
        inventory.push_back(std::move(weapon));
    }

    std::cout << "Weapon added to inventory successfully.\n";
}

void showInventory()
{
    std::cout << "\n=== Inventory ===\n";

    if (inventory.empty())
    {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    for (std::size_t i = 0; i < inventory.size(); ++i)
    {
        std::cout
            << i + 1
            << ". "
            << inventory[i]->getName()
            << '\n';
    }
}

void equipWeapon()
{
    if (equippedWeapon)
    {
        std::cout
            << "You already have "
            << equippedWeapon->getName()
            << " equipped.\n"
            << "Unequip it before choosing another weapon.\n";

        return;
    }

    if (inventory.empty())
    {
        std::cout << "Your inventory is empty. Create a weapon first.\n";
        return;
    }

    showInventory();

    std::cout << "Choose a weapon to equip: ";

    int choice = getOption();

    if (choice < 1 ||
        static_cast<std::size_t>(choice) > inventory.size())
    {
        std::cout << "Invalid weapon selection.\n";
        return;
    }

    std::size_t index = static_cast<std::size_t>(choice - 1);

    equippedWeapon = std::move(inventory[index]);

    inventory.erase(inventory.begin() + index);

    std::cout
        << equippedWeapon->getName()
        << " equipped successfully.\n";
}

void unequipWeapon()
{
    if (!equippedWeapon)
    {
        std::cout << "No weapon is currently equipped.\n";
        return;
    }

    std::string weaponName = equippedWeapon->getName();

    inventory.push_back(std::move(equippedWeapon));

    std::cout
        << weaponName
        << " was returned to the inventory.\n";
}

void showEquippedWeapon()
{
    std::cout << "\n=== Equipped Weapon ===\n";

    if (!equippedWeapon)
    {
        std::cout << "No weapon is currently equipped.\n";
        return;
    }

    std::cout
        << "Currently equipped: "
        << equippedWeapon->getName()
        << '\n';
}

void deleteWeapon()
{
    if (inventory.empty())
    {
        std::cout << "Your inventory is empty. There is nothing to delete.\n";
        return;
    }

    showInventory();

    std::cout << "Choose a weapon to delete: ";

    int choice = getOption();

    if (choice < 1 ||
        static_cast<std::size_t>(choice) > inventory.size())
    {
        std::cout << "Invalid weapon selection.\n";
        return;
    }

    std::size_t index = static_cast<std::size_t>(choice - 1);

    std::string weaponName = inventory[index]->getName();

    inventory.erase(inventory.begin() + index);

    std::cout
        << weaponName
        << " deleted successfully.\n";
}

bool menuManager()
{
    int choice = getOption();

    while (choice < 1 || choice > 7)
    {
        std::cout << "Invalid option. Please choose between 1 and 7: ";
        choice = getOption();
    }

    switch (choice)
    {
    case 1:
        createWeapon();
        break;

    case 2:
        showInventory();
        break;

    case 3:
        equipWeapon();
        break;

    case 4:
        unequipWeapon();
        break;

    case 5:
        showEquippedWeapon();
        break;

    case 6:
        deleteWeapon();
        break;

    case 7:
        return false;
    }

    return true;
}

void run()
{
    while (true)
    {
        std::cout
            << "\n========================================\n"
            << "        WEAPON INVENTORY SYSTEM\n"
            << "========================================\n"
            << "1. Create Weapon\n"
            << "2. Show Inventory\n"
            << "3. Equip Weapon\n"
            << "4. Unequip Weapon\n"
            << "5. Show Equipped Weapon\n"
            << "6. Delete Weapon\n"
            << "7. Exit\n"
            << "========================================\n"
            << "Select an option: ";

        if (!menuManager())
        {
            std::cout << "\nExiting Weapon Inventory System. Goodbye!\n";
            break;
        }
    }
}
