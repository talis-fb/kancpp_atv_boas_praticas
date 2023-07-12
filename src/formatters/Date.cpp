#include "../../include/formatters/Date.h"

std::string formatDate(tm date)
{
    std::stringstream ss;
    ss << date.tm_mday << "/" << date.tm_mon + 1 << "/" << date.tm_year + 1900;
    return ss.str();
}