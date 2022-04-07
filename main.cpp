#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;

void check_input(int argc, char **argv, int &max, bool &print_needed)
{
    if (argc == 1 || argc > 3)
    {
        cout << "correct usage #1:\n";
        cout << "./a.out max_int\n";
        cout << "correct usage #2:\n";
        cout << "./a.out max_int print\n";
        cout << "#1 just shows you basic info, #2 also prints all found primes\n";
        cout << "examples:\n";
        cout << "./a.out 100\n";
        cout << "./a.out 100 print\n";
        exit(0);
    }
    else if (argc == 2)
    {
        max = atoi(argv[1]);
        if (max <= 2)
        {
            cout << "the only prime <= 2 is 2, input greater max_int";
            exit(0);
        }
    }
    else
    {
        if (strcmp(argv[2], "print"))
        {
            cout << "second argument can only be \"print\"\n";
            exit(0);
        }
        print_needed = true;
        max = atoi(argv[1]);
        if (max <= 2)
        {
            cout << "the only prime <= 2 is 2, input greater max_int";
            exit(0);
        }
    }
}

int main(int argc, char **argv)
{
    int max;
    bool print_needed = false;
    check_input(argc, argv, max, print_needed);

    int iterations = 0;
    int last_iterative_process = 0;
    int i = 0;
    std::vector<int> primes = {2};

    for (i = 3; i < max; i += 2)
    {
        bool is_prime = true;

        int max = i / primes[0];

        last_iterative_process = 0;

        for (int j = 0; primes[j] < max; j++)
        {
            last_iterative_process++;
            iterations++;

            if (i % primes[j] == 0)
            {
                is_prime =false;
                break;
            }
            
            max = i / primes[j];
            max += primes[j];
        }

        if (is_prime)
            primes.push_back(i);
    }

    for (int k = 0; k < primes.size() && print_needed; k++)
        cout << primes[k] << " ";

    double percentage = (double)primes[primes.size() - 1];
    percentage /= i;
    percentage *= 100;

    cout << "\n\n" << primes.size() << " primes found in (0;" << i-1 << ")\n";
    cout << percentage << " %\n";
    cout << iterations << " iterations\n";
    cout << last_iterative_process << " last iterative process" << endl;

    return 0;
}