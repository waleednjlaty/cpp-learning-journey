#include <string>
class Weapon
{
private:
    std::string name;

public:
    Weapon(const std::string &name)
        : name(name)
    {
    }

    virtual ~Weapon() = default;

    const std::string &getName() const
    {
        return name;
    }
};

class Rifle : public Weapon
{
public:
    Rifle(const std::string &name)
        : Weapon(name)
    {
    }
};

class Pistol : public Weapon
{
public:
    Pistol(const std::string &name)
        : Weapon(name)
    {
    }
};

class Knife : public Weapon
{
public:
    Knife(const std::string &name)
        : Weapon(name)
    {
    }
};