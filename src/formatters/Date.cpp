#include "../../include/formatters/Date.h"

std::string formatDate(tm date)
{
    std::string formattedDate = std::to_string(date.tm_mday) + "/" + std::to_string(date.tm_mon + 1) + "/" + std::to_string(date.tm_year + 1900);

    return formattedDate;
}