#include <iostream>
#include <cstring>
#include <cstdio>

struct Stats
{
    unsigned long long lines = 0;
    unsigned long long words = 0;
    unsigned long long bytes = 0;
    unsigned long long alnum = 0;
};

Stats count_file(FILE *file)
{
    Stats stats;

    bool has_char = false;
    char last_char = '\0';
    bool in_word = false;

    const std::size_t BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE];
    std::size_t bytes_read = 0;

    while ((bytes_read = std::fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0)
    {
        for (std::size_t j = 0; j < bytes_read; j++)
        {
            char ch = buffer[j];
            has_char = true;
            last_char = ch;
            stats.bytes++;

            if (ch == '\n')
            {
                stats.lines++;
            }

            if (ch == ' ' || ch == '\t' || ch == '\n' ||
                ch == '\r' || ch == '\v' || ch == '\f')
            {
                in_word = false;
            }
            else if (!in_word)
            {
                stats.words++;
                in_word = true;
            }

            unsigned char uch = static_cast<unsigned char>(ch);

            if ((uch >= 'A' && uch <= 'Z') ||
                (uch >= 'a' && uch <= 'z') ||
                (uch >= '0' && uch <= '9'))
            {
                stats.alnum++;
            }
        }
    }

    if (has_char && last_char != '\n')
    {
        stats.lines++;
    }

    return stats;
}

int main(int argc, char **argv)
{
    bool count_lines = false;
    bool count_bytes = false;
    bool count_words = false;
    bool count_alnum = false;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (std::strcmp(argv[i], "-l") == 0 ||
                std::strcmp(argv[i], "--lines") == 0)
            {
                count_lines = true;
            }

            if (std::strcmp(argv[i], "-w") == 0 ||
                std::strcmp(argv[i], "--words") == 0)
            {
                count_words = true;
            }

            if (std::strcmp(argv[i], "-c") == 0 ||
                std::strcmp(argv[i], "--bytes") == 0)
            {
                count_bytes = true;
            }

            if (std::strcmp(argv[i], "-a") == 0 ||
                std::strcmp(argv[i], "--alnum") == 0)
            {
                count_alnum = true;
            }

            if (argv[i][1] != '-')
            {
                for (int j = 1; argv[i][j] != '\0'; j++)
                {
                    if (argv[i][j] == 'l')
                    {
                        count_lines = true;
                    }

                    if (argv[i][j] == 'w')
                    {
                        count_words = true;
                    }

                    if (argv[i][j] == 'c')
                    {
                        count_bytes = true;
                    }

                    if (argv[i][j] == 'a')
                    {
                        count_alnum = true;
                    }
                }
            }
        }
    }

    if (!count_lines && !count_words && !count_bytes && !count_alnum)
    {
        count_lines = true;
        count_words = true;
        count_bytes = true;
    }

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            continue;
        }

        FILE *file = std::fopen(argv[i], "rb");

        if (file == nullptr)
        {
            std::cerr << "Cannot open file: " << argv[i] << '\n';
            continue;
        }

        Stats stats = count_file(file);

        if (count_lines)
        {
            std::cout << stats.lines << ' ';
        }

        if (count_words)
        {
            std::cout << stats.words << ' ';
        }

        if (count_alnum)
        {
            std::cout << stats.alnum << ' ';
        }

        if (count_bytes)
        {
            std::cout << stats.bytes << ' ';
        }

        std::cout << argv[i] << '\n';

        std::fclose(file);
    }

    return 0;
}
