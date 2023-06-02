#include "HelperFunction.h"

bool HelperFunction::isYes(std::string y)
{
    return (y == "y" || y == "yes" || y == "Y" || y == "YES" || y == "Yes");
}

bool HelperFunction::isNo(std::string n)
{
    return (n == "n" || n == "no" || n == "N" || n == "NO" || n == "No");
}

bool HelperFunction::isSameWords(std::string first, std::string second)
{
    if (first.size() != second.size())
    {
        return false;
    }

    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] != second[i] && first[i] != second[i] - 32 && first[i] != second[i] + 32)
        {
            return false;
        }
    }
    return true;
}

