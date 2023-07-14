#ifndef DATE_FORMATTER
#define DATE_FORMATTER

#include <ctime>
#include <sstream>
#include <string>

/**
 * @brief Formats a date to a string
 * @param date The date to format
 * @return The formatted date on the form dd/mm/yyyy
 */
std::string formatDate(tm date);

#endif