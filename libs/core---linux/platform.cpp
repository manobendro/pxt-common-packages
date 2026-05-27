#include "pxt.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

namespace pxt {

static void initRandomSeed() {
    int seed = 0xC0DA1;
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, &seed, sizeof(seed));
    close(fd);
    seedRandom(seed);
}

void sendSerial(const char *data, int len) {
    // Host VM/linux runtime: write serial (console.log) to stdout.
    fwrite(data, 1, len, stdout);
    fflush(stdout);
}

extern "C" void drawPanic(int code)
{
    // TODO
}


extern "C" void target_init()
{
    initRandomSeed();
}

void updateScreen(Image_ img);

void screen_init() {
    updateScreen(NULL);
}

}

