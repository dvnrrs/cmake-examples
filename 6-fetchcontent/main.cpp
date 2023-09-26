#include <w/handle.hpp>
#include <unistd.h>

int main()
{
    typedef w::handle<int, -1, ::close> fd;
    fd standard_input(STDIN_FILENO);
}
