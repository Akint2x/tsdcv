#pragma once
#include <string>

class Obfuscator
{
public:
    // Function to obfuscate a string at compile-time.
    template <size_t N>
    static constexpr auto obfuscate(const char(&data)[N])
    {
        std::array<char, N> obfuscatedData = {};
        for (size_t i = 0; i < N; ++i)
        {
            obfuscatedData[i] = data[i] ^ key;
        }
        return obfuscatedData;
    }

    // Function to deobfuscate a string at runtime.
    static std::string deobfuscate(const std::string& data)
    {
        std::string result = data;
        for (char& c : result)
        {
            c ^= key;
        }
        return result;
    }

private:
    static constexpr char key = 0x5A;  // XOR key for obfuscation/deobfuscation
};

// Macro to easily use the obfuscator in the code.
#define _xor(str) Obfuscator::deobfuscate(str)
