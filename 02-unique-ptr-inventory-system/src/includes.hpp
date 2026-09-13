#include "Weapons.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <vector>

std::vector<std::unique_ptr<Weapon>> inventory;
std::unique_ptr<Weapon> equippedWeapon;
#include "functions.hpp"