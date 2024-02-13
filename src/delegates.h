#ifndef DELEGATES_H_
#define DELEGATES_H_

#include <functional>
#include <string>

using runnable = std::function<void()>;
using stringconsumer = std::function<void(const std::string&)>;
using wstringsupplier = std::function<std::wstring()>;
using wstringconsumer = std::function<void(const std::wstring&)>;

#endif // DELEGATES_H_
